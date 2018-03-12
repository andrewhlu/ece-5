int x = 0;
float vout = 0;
float y = 0;
void setup() {
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
  delay(2000);
  for (int x=0; x<=31; x++){
    PORTB = x;
    y=analogRead(A0);
    vout=5*(y/1024);
    Serial.println(vout);
  }
}
void loop() {

}
