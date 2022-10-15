#include <Servo.h>

const int switchPin = 13;
const int servoPin = 2;
Servo servo;

void setup()
{
  pinMode(switchPin, INPUT_PULLUP);
  servo.attach(servoPin);
}

void loop()
{
  if (digitalRead(switchPin))
  {
    servo.write(0);
  }
  else
  {
    servo.write(77);
  }

  delay(300);
}
