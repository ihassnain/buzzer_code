#include "PinsB10.h"

bool debug = true;

bool roboremo_drive = true;
                                                                                                                                                                             


long command = 0;


void print_message(String );
void setup_communication();
void setup_motors();
void setup_bldc_motors();
void enable_motors();
void enable_bldc_motors();
void forward();
void bldc_forward();
void bldc_apply_pwm();
void reverse();
void bldc_reverse();
void left();
void right();
void bldc_right();
void bldc_left();
void stop_motors();
void bldc_stop_motors();
void bldc_disable_motors();
void run_navigation_commands(int );
int exec_serial_commands();
void run_command(long );
void set_right_pwm(int );
void set_left_pwm(int );
void bldc_disable_motors();
void enable_bldc_motors();
void buzzer(int sec , int itr);
void buzz_detect(int com );

long bt_baud_rate = 9600;
long serial_baud_rate= 115200;

void setup_communication()
{

  Serial.begin(serial_baud_rate);
  Serial3.begin(bt_baud_rate );
  Serial2.begin(bt_baud_rate );

 // print_message("start with rover again");
}

void print_message(String msg)
{
  Serial.println(msg);
  /* Serial1.println(msg); */
  /* Serial2.println(msg); */
  Serial3.println(msg);
}


/*
 * Get user input
 */

int exec_serial_commands()
{
 int  command = 0;
 
 
   if (Serial.available())
    {
      command = Serial.parseInt();
    }
    /* bluetooth */
    if (Serial3.available())
    {
      command = Serial3.parseInt();
    }

//    if (Serial2.available())
//    {
//      command = Serial2.parseInt();
//    }

  run_command(command);
  return command;
}

void run_command(long com)
{
  if (com == 0)
    return;

  //print_message("");
  //print_message("command: " + String(com) + " ");

    if (com > 300 && com < 350)
  {
    buzz_detect(com);
  }


     
 
  command = 0;
}








void buzz_detect(int com)

{
  com =com-300;
  switch (com)
  {

  case 1:
    print_message("Obstacle Detected");
    buzzer(500,3);
    break;

  case 2:
    print_message("Goal Reached");
    buzzer(2000,2);
    break;
  
  case 3:
    print_message("Start Navigation");
    buzzer(3000,1);
    break;

  }
}
void buzzer(int mili_sec, int iteration)
{
  for(int i=0;i<iteration;i++)
  {
    tone(buzz_pin,2000);
      delay(mili_sec);
     noTone(buzz_pin);
     delay(1000);
  }
}



void setup()
{
  //analogWrite(R1SW_pin, 0);
 // eyes_reset();
  setup_communication(); 
  // setup_motors();
}

void loop()
{
   exec_serial_commands();
}
