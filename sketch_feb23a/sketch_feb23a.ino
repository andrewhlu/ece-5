const int redPin = 11;
const int greenPin = 12;
const int bluePin = 13;

const int trigPin = 7;
const int echoPin1 = 8;
const int echoPin2 = 9;
const int echoPin3 = 10;

float distance1, distance2, distance3;

void setup() {
  // put your setup code here, to run once:
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
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  distance1 = ((pulseIn(echoPin1, HIGH))*0.0343)/2;
  distance2 = ((pulseIn(echoPin2, HIGH))*0.0343)/2;
  distance3 = ((pulseIn(echoPin3, HIGH))*0.0343)/2;

  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  
  if(distance1 < distance2 && distance1 < distance3) {
    digitalWrite(redPin, HIGH);
  }
  else if(distance2 < distance1 && distance2 < distance3) {
    digitalWrite(greenPin, HIGH);
  }
  else if(distance3 < distance1 && distancce3 < distance2) {
    digitalWrite(bluePin, HIGH);
  }

  String outputString = String("L: ") + distance1 + " M: " + distance2 + " R: " + distance3;

  Serial.println(outputString);
  delay(50);
}
