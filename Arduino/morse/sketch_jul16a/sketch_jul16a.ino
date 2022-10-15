#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

unsigned long signal_len, t1, t2; // time for which button is pressed
int inputPin = 2; // input pin for push button
int ledPin = 4; // input pin for LED
String code = ""; // string in which one alphabet is stored


void setup() {
  Serial.begin(9600);
  pinMode(inputPin, INPUT_PULLUP); // internal pullup resistor is used to simplify the circuit
  pinMode(ledPin, OUTPUT);

  lcd.begin(16,2);
  lcd.clear();
}


void loop() {
  NextDotDash:
    while (digitalRead(inputPin) == HIGH) {}
    t1 = millis();  // time at button press
    digitalWrite(ledPin, HIGH); // LED on while button pressed

    while (digitalRead(inputPin) == LOW) {}
    t2 = millis(); // time at button release
    digitalWrite(ledPin, LOW); // LED off on button release
    
    signal_len = t2 - t1; // time for which button is pressed

    if (signal_len > 50) {
      code += readio(); // function to read dot or dash
    }

    while ((millis() - t2) < 600) { // skip to next alphabet
      if (digitalRead(inputPin) == LOW) {
        goto NextDotDash;
      }
    }
    convertor(); // function to decipher code into alphabet
}


char readio() {
  if (signal_len < 300 && signal_len > 50) {
    return '.';  
  }
  else if (signal_len > 300) {
    return '-';
  }
}


void convertor() {
  static String letters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--." , "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "E"};
  int i = 0;
  if (code == ".-.-.-") {
    lcd.print(".");
  }
  else {
    while (letters[i] != "E") {
      if (letters[i] == code) {
        lcd.print(char('A' + i));
        break;
      }
      i++;
    }
    if (letters[i] == "E") {
      lcd.println("");
    }
  }
  code = ""; // reset code to blank string
}
