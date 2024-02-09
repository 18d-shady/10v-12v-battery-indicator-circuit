/*
  Resistors are aligned in series.
  One end goes to Battery - and also to Arduino GND
  The other goes to Battery + and also to Arduino Vin
  The middle (connection between two resistors) goes to Arduino A0
*/
#include <Wire.h>

#define RED_LED 12
#define RED_LED2 11
#define YELLOW_LED 10
#define GREEN_LED 9
float R1 = 47000.0;
float R2 = 33250.0;

void setup() {  
  Serial.begin(115200);
  pinMode(RED_LED, OUTPUT);
  pinMode(RED_LED2, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(A0, INPUT);
  digitalWrite(RED_LED, LOW);
  digitalWrite(RED_LED2, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
}

void loop() {
  int sensorValue = analogRead(A0); //read the A0 pin value
  //int sensorValue = 900;
  float voltage = sensorValue * (5.00 / 1024.00) * ((R1 + R2)/R2); //convert the value to a true voltage.
  //float voltage = sensorValue / 4;
  Serial.println(voltage);
  delay(1000);

  if (voltage < 10) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(RED_LED2, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
  } else if ((voltage >= 10) && (voltage < 10.8)) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(RED_LED2, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
  } else if ((voltage >= 10.8) && (voltage < 11.4)) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(RED_LED2, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
  } else if ((voltage >= 11.4) && (voltage < 11.95)) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(RED_LED2, HIGH);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  } else if ((voltage >= 11.95) && (voltage <= 12.4)) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(RED_LED2, HIGH);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
  } 
  /*else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(RED_LED2, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }*/

}
 