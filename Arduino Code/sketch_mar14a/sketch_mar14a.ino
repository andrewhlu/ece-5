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
  float distValues1[] = {getDistance(echoPin1), getDistance(echoPin2), getDistance(echoPin3), getDistance(echoPin4), getDistance(echoPin5)};
  float distValues2[] = {getDistance(echoPin1), getDistance(echoPin2), getDistance(echoPin3), getDistance(echoPin4), getDistance(echoPin5)};
  float distValues3[] = {getDistance(echoPin1), getDistance(echoPin2), getDistance(echoPin3), getDistance(echoPin4), getDistance(echoPin5)};
  float distValues4[] = {getDistance(echoPin1), getDistance(echoPin2), getDistance(echoPin3), getDistance(echoPin4), getDistance(echoPin5)};
  float distValues5[] = {getDistance(echoPin1), getDistance(echoPin2), getDistance(echoPin3), getDistance(echoPin4), getDistance(echoPin5)};

  float avgValue[5];

  for(int i = 0; i < 5; i++) {
    avgValue[i] = averageValue(i, distValues1, distValues2, distValues3, distValues4, distValues5);
  }

  float minDist = minDistance(avgValue);

  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);

  if(minDist == 0) {
    //Red
    digitalWrite(redPin, HIGH);
    swiper.write(5);
  }
  else if(minDist == 1) {
    //Magenta
    digitalWrite(redPin, HIGH);
    digitalWrite(bluePin, HIGH);
    swiper.write(45);
  }
  else if(minDist == 2) {
    //Green
    digitalWrite(greenPin, HIGH);
    swiper.write(90);
  }
  else if(minDist == 3) {
    //Cyan
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
    swiper.write(135);
  }
  else if(minDist == 4) {
    //Yellow
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    swiper.write(175);
  }

  if(minDist == 0) {
    String outputString = String("#S|SOUND|[]#");
    Serial.println(outputString);
    delay(2000);
  }
}

float getDistance(int readPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  int pulse = ((pulseIn(readPin, HIGH, 10000))*0.0343)/2;

  if(pulse == 0) {
    pulse = 9999;
  }

  delay(5);
  
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

float averageValue(int index, float *distArray1, float *distArray2, float *distArray3, float *distArray4, float *distArray5) {
  float avgValue = 0;

  int counter = 5;
  if(distArray1[index] == 9999) {
    counter = counter - 1;
  }
  else {
    avgValue = avgValue + distArray1[index];
  }
  if(distArray2[index] == 9999) {
    counter = counter - 1;
  }
  else {
    avgValue = avgValue + distArray2[index];
  }
  if(distArray3[index] == 9999) {
    counter = counter - 1;
  }
  else {
    avgValue = avgValue + distArray3[index];
  }
  if(distArray4[index] == 9999) {
    counter = counter - 1;
  }
  else {
    avgValue = avgValue + distArray4[index];
  }
  if(distArray5[index] == 9999) {
    counter = counter - 1;
  }
  else {
    avgValue = avgValue + distArray5[index];
  }
  
  if(counter < 4) {
    avgValue = 9999;
  }
  else {
    avgValue = avgValue/counter;
  }
  
  return avgValue;
}

