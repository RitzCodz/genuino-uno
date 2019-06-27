long x=0, y=0;
long i,xi,yi;

int LMP = 6;
int LMN = 5;
int RMP = 10;
int RMN = 11;
char c;
char d;


void front() {
  digitalWrite(RMP, 1);    digitalWrite(RMN, 0);
  digitalWrite(LMN, 1);    digitalWrite(LMP, 0);
}
void back() {
  digitalWrite(RMP, 0);    digitalWrite(RMN, 1);
  digitalWrite(LMN, 0);    digitalWrite(LMP, 1);
}
void fleft() {
  digitalWrite(RMP, 1);    digitalWrite(RMN, 0);
  digitalWrite(LMN, 0);    digitalWrite(LMP, 1);
}
void fright() {
  digitalWrite(RMP, 0);    digitalWrite(RMN, 1);
  digitalWrite(LMN, 1);    digitalWrite(LMP, 0);
}
void bleft() {
  digitalWrite(RMP, 0);    digitalWrite(RMN, 1);
  digitalWrite(LMN, 1);    digitalWrite(LMP, 0);
}
void bright() {
  digitalWrite(RMP, 1);    digitalWrite(RMN, 0);
  digitalWrite(LMN, 0);    digitalWrite(LMP, 1);
}
void stopp() {
  digitalWrite(RMP, 0);    digitalWrite(RMN, 0);
  digitalWrite(LMN, 0);    digitalWrite(LMP, 0);
}
void setup() {

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  // Serial.print("\nEnter a key:");
}


void loop() {
   x=0;y=0;
 for(i=0;i<500;i++){
    xi= analogRead(A2);
    yi= analogRead(A3);
    x+=xi;y+=yi;
  }
  x/=500;
  y/=500;
  Serial.print("x: ");Serial.print(x);Serial.print("y: ");Serial.println(y);
  if (x > 370)  front();
  else if (x < 290)  back();
  else {
  if (y > 370)  fleft();
  else if (y < 290)  fright();
  else stopp();
  }
}
