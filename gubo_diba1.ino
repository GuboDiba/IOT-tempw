#include <Servo.h>
#define temperature A0
Servo mainServo;
int position = 0;
int position2;
void setup() {
  pinMode(temperature, INPUT);
  mainServo.attach(6);
  Serial.begin(9200);
}
void loop(){
int tempReading = analogRead(temperature);
  float voltage = tempReading *5.0;
  voltage /= 1024.0;
  float tempC = (voltage - 0.5) *100;
    int position = map(tempC, 0, 50, 0, 90);
  Serial.println(position);
  if(position2 >30){
     mainServo.write(90);
    delay(500);
  }
}