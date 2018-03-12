  int datapin = 8;
  int latchpin = 9;
  int clockpin = 10;
  int pattern[] = {192, 249, 164, 176, 153, 146, 130, 248, 128, 144};
  int DIG1 = 2;
  int DIG2 = 3;
  int DIG3 = 4;
  int DIG4 = 5;

void setup() {
  pinMode(datapin,OUTPUT);
  pinMode(latchpin,OUTPUT);
  pinMode(clockpin,OUTPUT);
  pinMode(DIG1,OUTPUT);
  pinMode(DIG2,OUTPUT);
  pinMode(DIG3,OUTPUT);  
  pinMode(DIG4,OUTPUT);
}

void loop() {
  int i = millis() / 1000;

  writedigit(1, pattern[(i % 10000) / 1000]);
  delay(4);
  writedigit(2, pattern[(i % 1000) / 100]);
  delay(4);
  writedigit(3, pattern[(i % 100) / 10]);
  delay(4);
  writedigit(4, pattern[(i % 10) / 1]);
  delay(4);
  
//  for(int i = 0; i < 10;i++) {
//    writedigit(pattern[i]);
//    delay(1000);
//  }
}

void writedigit(int whichdigit, int number) {
  digitalWrite(latchpin,LOW); //"unlocks" the S.R
  shiftOut(datapin,clockpin,MSBFIRST, 255); //load the data onto the S.R
  digitalWrite(latchpin,HIGH); //"lock" the SR and display the new data

  //turnning on digits
  int onoff[] = {0,0,0,0};
  onoff[whichdigit - 1]= 1;
  digitalWrite(DIG1,onoff[0]);
  digitalWrite(DIG2,onoff[1]);
  digitalWrite(DIG3,onoff[2]);
  digitalWrite(DIG4,onoff[3]);

    digitalWrite(latchpin,LOW); //"unlocks" the S.R
  shiftOut(datapin,clockpin,MSBFIRST, number); //load the data onto the S.R
  digitalWrite(latchpin,HIGH); //"lock" the SR and display the new data
}

