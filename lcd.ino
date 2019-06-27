#include <LiquidCrystal.h>
int rs = 12, e = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal learn(rs, e, d4, d5, d6, d7);

void setup() {
  learn.begin(16, 2);
  learn.setCursor(3, 1);
  learn.print("Hey There!");

}

void loop() {
  learn.setCursor(5, 1);
  learn.print("Hello");
  delay(1000);
  learn.setCursor(5, 1);
  learn.print("     ");
  delay(1000);

  learn.setCursor(7, 1);
  learn.print("Hi!");
  delay(1000);
  learn.setCursor(5, 1);
  learn.print("     ");
  delay(1000);
}
