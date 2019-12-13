#define MR1 3
#define MR2 4
#define ML1 5
#define ML2 6
#define Speed 90
#define LS   A0
#define RS   A2 // black line output low, white line output high
#define CS  A1
#define echopin 8// echo pin
#define trigpin 7 // Trigger pin
int  frontDistance;
long duration;
int R , L , C ; // integers for sensor readings
void setup() {
  pinMode(MR1, OUTPUT);
  pinMode(ML1, OUTPUT);
  pinMode(MR2, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(CS, INPUT);
  pinMode (trigpin, OUTPUT);
  pinMode (echopin, INPUT);
}

void loop() {
  R = digitalRead(RS);
  L = digitalRead(LS);// sensor reading
  C = digitalRead(CS);
//  frontDistance = DistanceCalc(); // odamo add eh w ykhbat
//  if (frontDistance > 5 ) { // lw odamo el seka salka khalsa ykmle
    if (R == 1 && L == 1 && C == 0) {
      forward(); // the robot is in his track
    }
    else if (R == 0 && L == 1) {
      Right(); // hyzbot 7alo ymen 34an sensor el ymeen 2ary eno 3aala el track
    }
    else if (R == 1 && L == 0) {
      Left(); // hyzbot 7alo Shmal 34an sensor el Shmal 2ary eno 3aala el Track
    }
    else if (R == 0 && L == 0 && C == 0) {
      Stop(); // el talata 2reeen eswd fa kda stop
    }
//  }
//  else {
//    Skip(); // wasal hena yb2a el seka msh salka fa hay5la3
//  }
//Z();
}
void forward() {
  analogWrite(MR1, Speed);
  analogWrite(ML1, Speed);
  digitalWrite(MR2, LOW);
  digitalWrite(ML2, LOW);
}
void Stop() {
  digitalWrite(MR1, LOW);
  digitalWrite(MR2, LOW);
  digitalWrite(ML1, LOW);
  digitalWrite(ML2, LOW);
}
void backward() {
  analogWrite(MR2, Speed);
  analogWrite(ML2, Speed);
  digitalWrite(MR1, LOW);
  digitalWrite(ML1, LOW);

}
void Right() {
  analogWrite(MR1, Speed);
  digitalWrite(MR2, LOW);
  digitalWrite(ML1, LOW);
  digitalWrite(ML2, LOW);
}
void Left() {
  analogWrite(ML1, Speed);
  digitalWrite(MR2, LOW);
  digitalWrite(MR1, LOW);
  digitalWrite(ML2, LOW);
}
int DistanceCalc() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  return duration * 0.034 / 2; // in CMs
}
void Skip() {
  Left();
  delay(300);
  forward();
  delay(1000);
  Right();
  delay(300);
  forward();
  delay(750);
  Right();
  delay(300);
  forward();
}
void Z() {
  forward();
  delay(2000);
  Stop();
  delay(2000);
  backward();
  delay(2000);
  Stop();
  delay(2000);
  Left();
  delay(2000);
  Stop();
  delay(2000);
  Right();
  delay(2000);
  Stop();
  delay(2000);
}
