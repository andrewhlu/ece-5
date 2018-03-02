#include <Servo.h>

Servo swiper;

int pos = 0;

void setup() {
  // put your setup code here, to run once:
  swiper.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  swiper.write(180);
  delay(1000);
  swiper.write(0);
  delay(1000);
}
