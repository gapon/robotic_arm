#include <Servo.h>

Servo servo1;
Servo servo2;
String message, servo, angle_str;
int ind, angle_int;


int pos1 = 0;    // variable to store the servo position
int pos2 = 0;

void setup() {
  Serial.begin(9600);
  servo1.attach(9);  // attaches the servo on pin 9 to the servo object
  servo2.attach(10);

  // TIMSK0=0;
}

void loop() {
  
  while (Serial.available() > 0)
  {
    char recieved = Serial.read();
    message += recieved;
    
    if (recieved == '\n')
    {
      Serial.print("Received: ");
      Serial.println(message);

      ind = message.indexOf(':');
      servo = message.substring(0, ind);
      angle_str = message.substring(ind+1);

      angle_int = atoi(angle_str.c_str());

      Serial.print("Servo: ");
      Serial.println(servo);

      Serial.print("Angle: ");
      Serial.println(angle_int);


      if (servo == "servo1")
      {
        for (int pos = 0; pos <= angle_int; pos += 1)
        {
          servo1.write(pos);
          delay(15);
        }
      }
      else if (servo == "servo2")
      {
        for (int pos = 0; pos <= angle_int; pos += 1)
        {
          servo2.write(pos);
          delay(50);
        }
      }
      
      message = "";


    }
  }
  
}
