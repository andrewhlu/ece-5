const int trigPin = 6;
const int echoPin1 = 7;
const int echoPin2 = 8;
const int echoPin3 = 9;
const int redPin = 10;
const int greenPin = 11;
const int bluePin = 12;

int threshold = 150;

float distance1, distance2, distance3;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  distance1 = getDistance(echoPin1);
  distance2 = getDistance(echoPin2);
  distance3 = getDistance(echoPin3);

  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  
  if(distance1 < distance2 && distance1 < distance3 && distance1 < threshold) {
    digitalWrite(redPin, HIGH);
  }
  else if(distance2 < distance1 && distance2 < distance3 && distance2 < threshold) {
    digitalWrite(greenPin, HIGH);
  }
  else if(distance3 < distance1 && distance3 < distance2 && distance3 < threshold) {
    digitalWrite(bluePin, HIGH);
  }

  String outputString = String("L: ") + distance1 + " M: " + distance2 + " R: " + distance3;

  Serial.println(outputString);
  delay(50);
}

float getDistance(int readPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  int pulse = ((pulseIn(readPin, HIGH))*0.0343)/2;

  if(pulse == 0) {
    pulse = 9999;
  }
  
  return pulse;
}
