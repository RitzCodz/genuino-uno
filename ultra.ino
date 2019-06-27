int trig = 18;
int echo = 19;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(18,OUTPUT);
pinMode(19,INPUT);
}

void loop() {
  digitalWrite(trig,1);
  delayMicroseconds(5);
    digitalWrite(trig,0);
  delayMicroseconds(2);
    digitalWrite(trig,1);

   long timee=pulseIn(echo,1);

   float dis=344*timee/20000;
   Serial.println(dis);
   delay(100);
 
}
