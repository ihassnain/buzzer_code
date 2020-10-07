/*
   rosserial Subscriber Example
   Blinks an LED on callback
*/

#include <ros.h>
#include <std_msgs/Int32.h>

ros::NodeHandle  nh;
int buzzer =8;
int common_delay =500;
int delay_stop =2000;
int delay_reached =2000;

int tune_freq = 1500;

void buzzup(int buzz_delay, int numb)
{for(int i=0;i<numb;i++)
{
  tone(buzzer, tune_freq);
  delay(buzz_delay);

  noTone(buzzer);
  delay(buzz_delay);
  Serial.print("ms delay: ");
  Serial.println(buzz_delay);

}
}



void callback_buzzer( const std_msgs::Int32& msg) {
  
  if (msg.data == 403)
  {

    buzzup(common_delay,2);
  }
  else if (msg.data == 401)
  {
    buzzup(common_delay ,3);
  }
  else if (msg.data == 406)
  {
    buzzup(common_delay, 4);
  }

  else if (msg.data == 405)
  {
    buzzup(delay_reached,2);
  }
  else if (msg.data == 400)
  {
    buzzup(delay_stop,1);
  }
  else if ( msg.data > 1000)
  {
    tune_freq = msg.data;
    Serial.print("tune freq set to: ");
    Serial.println(tune_freq);
  }
  else
  {
    noTone(buzzer);
  }
}

ros::Subscriber<std_msgs::Int32> sub("buzzer", &callback_buzzer );

void setup()
{
  pinMode(buzzer, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  Serial.begin(57600);
}

void loop()
{
  nh.spinOnce();
  delay(1);
}
