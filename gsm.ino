#include <SoftwareSerial.h>
SoftwareSerial gsm(10, 11);    //10=rx, 11=tx
char a[200];
int i;
void setup() {
  gsm.begin(9600);
  Serial.begin(9600);
  gsm.println("AT");                                                     //transmit at command to gsm. GSM must reply "OK"   ::  it must be println not print
  delay(500);
  gsm.println("AT+CLIP=1");
  delay(500);
}
void call() {
  gsm.println("ATD+ +917902913319;");
  delay(5000);
}
void cut() {
  gsm.println("ATH");
  delay(500);
}

void sendsms() {
  Serial.print("What do you want to send? Max 100 letters\n");
  delay(3000);
  Serial.read(); //to read the bugging blank space
 while(!(Serial.available()));            //to wait until user sends data
  for (i = 0; i < 100; i++) {
    if (Serial.available()) {
      a[i] = Serial.read();
      delay(10);
    }else break;
  }
    a[i] = '\0';
  gsm.println("AT+CMGF=1");
  delay(500);
  gsm.print("AT+CMGS=\"+917902913319\"\r");
  delay(500);
  gsm.print(a);
   // gsm.println("Hi how r u?");
  delay(100);
  gsm.write((char)26);
  delay(1000);
 
}

void loop() {
  if (gsm.available()) {
    Serial.println(gsm.readString());
  }

  char c = Serial.read();
  switch (c) {
    case 'c': call();
      break;
    case 'd': cut();
      break;
    case 's': sendsms();
      break;
  }

}
