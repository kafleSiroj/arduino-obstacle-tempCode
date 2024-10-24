#include <Servo.h>

int m1p1 = 2;
int m1p2 = 3;
int ena1 = 1; 
int m2p1 = 5;
int m2p2 = 6;
int ena2 = 4;
int echo = 12;
int trig = 13;
long duration;
int distance(); 

Servo myServo;

void stop();
void forward();
void reverseLeft();
void reverseRight();
void reverse();

void turnLeft();
void turnRight();

void setup() {
  pinMode(ena1, OUTPUT);
  pinMode(m1p1, OUTPUT);
  pinMode(m1p2, OUTPUT);
  pinMode(ena2, OUTPUT);
  pinMode(m2p1, OUTPUT);
  pinMode(m2p2, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  myServo.attach(11);
  myServo.write(90);
}

void stop() {
  analogWrite(ena1, 0);
  analogWrite(ena2, 0);
}

void forward() {
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW);
  analogWrite(ena1, 255);

  digitalWrite(m2p1, HIGH);
  digitalWrite(m2p2, LOW);
  analogWrite(ena2, 255);
}

void reverse() {
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, HIGH);
  analogWrite(ena1, 255);

  digitalWrite(m2p1, LOW);
  digitalWrite(m2p2, HIGH);
  analogWrite(ena2, 255);
}

void reverseLeft() {
  digitalWrite(m2p1, LOW);
  digitalWrite(m2p2, HIGH);
  analogWrite(ena2, 255);

  analogWrite(ena1, 0);
    
}

void reverseRight() {
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, HIGH);
  analogWrite(ena1, 255);

  analogWrite(ena2, 0);
}

int distance() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);

  return duration * 0.034 / 2;
}

void turnLeft() {
  stop();
  delay(1000);

  reverse();
  delay(1000);

  stop();
  delay(500);

  reverseLeft();
  delay(1000);
    
  stop();
  delay(500);
}

void turnRight() {
  stop();
  delay(1000);

  reverse();
  delay(1000);

  stop();
  delay(500);

  reverseRight();
  delay(1000);
  
  stop();
  delay(500);
}

void loop() {
  int Fdistance = distance();

  forward();
  
  if (Fdistance <= 10) {
    turnLeft();
  }


  else {
    myServo.write(90);
  }

  delay(100);

}


