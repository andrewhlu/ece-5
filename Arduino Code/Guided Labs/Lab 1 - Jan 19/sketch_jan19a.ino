int variable = 0;
int milli = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(3, INPUT);
  pinMode(9, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  variable = digitalRead(3);
  milli = millis();
  milli = abs(milli);
  Serial.println(milli);
  
  if(variable == 1) {
    if(milli % 500 < 250) {
      digitalWrite(9, HIGH);
    }
    else {
      digitalWrite(9, LOW);
    }
  }
  else {
    if(milli % 1000 < 500) {
      digitalWrite(9, HIGH);
    }
    else {
      digitalWrite(9, LOW);
    }
  }
}
