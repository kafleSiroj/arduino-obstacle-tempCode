int m1p1 = 2;
int m1p2 = 3;
int ena1 = 1; 
int m2p1 = 5;
int m2p2 = 6;
int ena2 = 4;
int echo = 12;
int trig = 13;
long duration;
int distance; 

void setup() {
  pinMode(m1p1, OUTPUT);
  pinMode(m1p2, OUTPUT);
  pinMode(m2p1, OUTPUT);
  pinMode(m2p2, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {

  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig, LOW);
  delayMicroseconds(10);

  duration = pulseIn(echo, HIGH);

  distance = duration * 0.032 / 2;

  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW);
  analogWrite(ena1, 255);

  digitalWrite(m2p1, HIGH);
  digitalWrite(m2p2, LOW);
  analogWrite(ena2, 255);

  if (distance <= 10) {
    digitalWrite(m1p1, LOW);
    digitalWrite(m1p2, HIGH);
    analogWrite(ena1, 255);

    digitalWrite(m2p1, LOW);
    digitalWrite(m2p2, HIGH);
    analogWrite(ena2, 255);
  }
}


