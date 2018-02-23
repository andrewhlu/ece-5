const int trigPin = 7;
const int echoPin1 = 8;
const int echoPin2 = 9;
const int echoPin3 = 10;

const int redPin = 11;
const int greenPin = 12;
const int bluePin = 13;

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
  
  if(distance1 < distance2 && distance1 < distance3) {
    digitalWrite(redPin, HIGH);
  }
  else if(distance2 < distance1 && distance2 < distance3) {
    digitalWrite(greenPin, HIGH);
  }
  else if(distance3 < distance1 && distance3 < distance2) {
    digitalWrite(bluePin, HIGH);
  }

  String outputString = String("L: ") + distance1 + " M: " + distance2 + " R: " + distance3;

  Serial.println(outputString);
  //delay(50);
}

float getDistance(readPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  return ((pulseIn(readPin, HIGH))*0.0343)/2;
}

