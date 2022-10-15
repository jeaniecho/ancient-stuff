int btn = 6;
int led = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(btn, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(btn) == HIGH) {
  digitalWrite(led, HIGH);
  }

  if (digitalRead(btn) == LOW) {
  digitalWrite(led, LOW);
  }
}
