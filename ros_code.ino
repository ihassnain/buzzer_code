/*
   rosserial Subscriber Example
   Blinks an LED on callback
*/

#include <ros.h>
#include <std_msgs/Int32.h>

ros::NodeHandle  nh;
int buzzer = 11;
int delay1 = 500;
int delay2 = 1000;
int delay3 = 1500;
int delay4 = 2000;
int tune_freq = 1000;

void buzzup(int buzz_delay)
{
  tone(buzzer, tune_freq);
  delay(buzz_delay);

  noTone(buzzer);
  delay(buzz_delay);
  Serial.print("ms delay: ");
  Serial.println(buzz_delay);

}



void callback_buzzer( const std_msgs::Int32& msg) {
  

  if (msg.data == 1)
  {

    buzzup(delay1);
  }
  else if (msg.data == 2)
  {
    buzzup(delay2);
  }
  else if (msg.data == 3)
  {
    buzzup(delay3);
  }

  else if (msg.data == 4)
  {
    buzzup(delay4);
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
