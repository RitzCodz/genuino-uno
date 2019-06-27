int p = 14;
int n = 15;

void setup() {
  // put your setup code here, to run once:
  pinMode(14,OUTPUT);
    pinMode(15,OUTPUT);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    char a = Serial.read();
    Serial.print(a);
    if (a == '1')
      digitalWrite(14, 1);
    else if (a == '0')
      digitalWrite(14, 0);
  }

}
