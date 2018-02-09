#include <Wire.h>
int on = 0;

void setup() {
  pinMode(13, OUTPUT);
  
  // put your setup code here, to run once:
  Wire.begin();

  Wire.beginTransmission(0x68);
  Wire.write(107);
  Wire.write(0);
  byte rc = Wire.endTransmission(true);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(0x68);
  Wire.write(59);
  Wire.endTransmission(false);
  Wire.requestFrom(0x68, 6, true);
  
  float x = ((Wire.read() << 8) | Wire.read())/16384.0;
  float y = ((Wire.read() << 8) | Wire.read())/16384.0;
  float z = ((Wire.read() << 8) | Wire.read())/16384.0;

  String outputString = String("X: ") + x + " Y: " + y + " Z: " + z;

  Serial.println(outputString);

  if(abs(x) >= 1.5 || abs(y) >= 1.5 || abs(z) >= 1.5) {
    if(on == 0) {
      digitalWrite(13, HIGH);
      on = 1;
    }
    else {
      digitalWrite(13, LOW);
      on = 0;
    }
  }
  
  delay(500);
}
