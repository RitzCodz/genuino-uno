#include<Servo.h>
Servo ser;
void setup() {
  Serial.begin(9600);
  digitalWrite(17,1);
  digitalWrite(16,0);
  ser.attach(3);
  int a=ser.read();
  Serial.print(a);
//  delay(5000);
//  for (int i = 0; i <= 180; i++) {
//    ser.write(i);
//    delay(15);
//  }
 ser.write(90);
  for (int i = 90; i <= 180; i++) {
   ser.write(i);
   delay(15);
 }
 for (int i = 180; i >= 0; i--) {
   ser.write(i);
   delay(15);
 }
  for (int i = 0; i <= 90; i++) {
   ser.write(i);
   delay(15);
 }
}

void loop() {
  // put your main code here, to run repeatedly:

}
