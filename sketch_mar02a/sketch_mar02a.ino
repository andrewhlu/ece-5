#include <Servo.h>
int pos = 0;
Servo swiper;

const int servoPin = 3;
const int trigPin = 4;
const int echoPin1 = 9;
const int echoPin2 = 8;
const int echoPin3 = 7;
const int echoPin4 = 6;
const int echoPin5 = 5;
const int redPin = 10;
const int greenPin = 11;
const int bluePin = 12;

const int threshold = 150;

void setup() {
  swiper.attach(servoPin);
  
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
  float distValues[] = {getDistance(echoPin1), getDistance(echoPin2), getDistance(echoPin3), getDistance(echoPin4), getDistance(echoPin5)};
  float minDist = minDistance(distValues);

  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);

  if(minDist == 0) {
    digitalWrite(redPin, HIGH);
    swiper.write(0);
  }
  else if(minDist == 1) {
    digitalWrite(redPin, HIGH);
    digitalWrite(bluePin, HIGH);
    swiper.write(45);
  }
  else if(minDist == 2) {
    digitalWrite(greenPin, HIGH);
    swiper.write(90);
  }
  else if(minDist == 3) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
    swiper.write(135);
  }
  else if(minDist == 4) {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    swiper.write(180);
  }

  String outputString = String("R: ") + distValues[0] + " Y: " + distValues[1] + " G: " + distValues[2] + " C: " + distValues[3] + " B: " + distValues[4];

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

float minDistance(float *distArray) {
  int lowestNum = 9999;
  int lowestIndex = -1;

  for(int i = 0; i < 5; i++) {
    if(distArray[i] < lowestNum && distArray[i] < threshold) {
      lowestNum = distArray[i];
      lowestIndex = i;
    }
  }

  return lowestIndex;
}
