#define LS   A0
#define RS   A2 // black line output low, white line output high
#define CS  A1
int R , L , C ; // integers for sensor readings

void setup() {
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(CS, INPUT);
  Serial.begin(9600);
}

void loop() {
  R = digitalRead(RS);
  L = digitalRead(LS);// sensor reading
  C = digitalRead(CS);
  Serial.print("RIGHT: ");
  Serial.println(R);


  Serial.print("Center: ");
  Serial.println(C);

  Serial.print("LEFT: ");
  Serial.println(L);
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
  delay(1000);
}
void forward() {
  Serial.println("FORWARD");
}
void Right() {
  Serial.println("RIGHT");
}
void Left() {
  Serial.println("LEFT");

}
void Stop() {
  Serial.println("STOP");

}
