const int trigPin = 6;
const int echoPin = 7;
#define GreenLED 11
#define YellowLED 10
#define RedLED 9
#define buzzer 3
int sound = 500;

void setup()
{
  Serial.begin(9600);
  pinMode(GreenLED,OUTPUT);
  pinMode(YellowLED,OUTPUT);
  pinMode(RedLED,OUTPUT);
  pinMode(buzzer,OUTPUT);
}

long distanceOverTime(long first, long second)
{
  return ((first - second) / 0.1) * 0.0223693629;
}

long holder;
long temp;
int counter;

void loop()
{
  long duration, inches, cm;
  int tens;
  int ones;
  long Speed;

  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  pinMode(echoPin,INPUT);
  duration = pulseIn(echoPin,HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  if (cm <= 50)
  {
    digitalWrite(GreenLED,HIGH);
  }
  else
  {
    digitalWrite(GreenLED,LOW);
  }

  if (cm <= 30)
  {
    digitalWrite(YellowLED,HIGH);
  }
  else
  {
    digitalWrite(YellowLED,LOW);
  }

  if (cm <= 15)
  {
    digitalWrite(RedLED,HIGH);
    sound = 1000;
    tone(buzzer,sound);
  }
  else
  {
    digitalWrite(RedLED,LOW);
    noTone(buzzer);
  }

  delay(300);
  Serial.print(cm);
  Serial.print(" cm ");
  Serial.println();
  delay(100);
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 /2;
}

