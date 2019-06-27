void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
int i;
char a[13]={};
char b[] = "1D0078592519";
char c[] = "1D0072BBE135";

void loop() {
  //Serial.println(Serial.available());
  if (Serial.available()) {
    for (i = 0; i < 12; i++) {
      a[i] = Serial.read();
      if(a[i]!=b[i]&&a[i]!=c[i])
      break;
      delay(10);
    }
   // Serial.print(a);
    if (i==12) {
      Serial.println("Access permitted");
    }
    else Serial.println("Access denied");
 }

 // delay(100);
}
