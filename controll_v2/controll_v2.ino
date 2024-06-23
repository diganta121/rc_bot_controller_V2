/*Arduino bobo
  Version 1.5
*/

//include the library code:

// use pin 3, 5, 6, 9, for output
//a b c d
//variables to store channel value:

double ch3 = 2;  //throttle ch3
double ch1 = 3;  //steer side-side ch1
double ch2 = 4;  //steer forward-back ch2


int a = 10;
int b = 9;
int c = 6;
int d = 5;


int forward_limt = 1;
int side_limt = 1;

// vars
int thr_inp = 0;
int for_inp = 0;
int side_inp = 0;

int motorSpeed1 = 0;  //variable to store motor speed:
int motorSpeed2 = 0;

int dir_f = 0;
int dir_s = 0;


void setup() {

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);


  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);

  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);

  Serial.begin(9600);
}

void loop() {

  ch1 = pulseIn(2, HIGH, 3000);  //speed
  ch2 = pulseIn(3, HIGH, 3000);  //front-back
  ch3 = pulseIn(4, HIGH, 3000);  //side-side

  Serial.print("ch: ");
  Serial.print(ch1);
  Serial.print(' ');
  Serial.print(ch2);
  Serial.print(' ');
  Serial.print(ch3);
  Serial.print(' ');

  thr_inp = map(ch3, 1000, 2000, 0, 200);
  for_inp = map(ch1, 1000, 2000, -20, 20);
  side_inp = map(ch2, 1000, 2000, -20, 20);
  
  Serial.print("m: ");
  Serial.print(thr_inp);
  Serial.print(' ');
  Serial.print(for_inp);
  Serial.print(' ');
  Serial.print(side_inp);
  Serial.print('\n');
  bool enabled = (thr_inp > 1);

  motorSpeed1 = 0;
  motorSpeed2 = 0;
  

  if (enabled) {
    if (for_inp >= forward_limt) {
      //forward
      motorSpeed1 += 2 + for_inp + thr_inp;
      motorSpeed2 += 2 + for_inp + thr_inp;

    } else if (for_inp <= -forward_limt) {
      motorSpeed1 -= 2 + thr_inp;
      motorSpeed2 -= 2 + thr_inp;
    } else {
      stop();
    }

    // sideways movement
    if (side_inp > side_limt) {
      //RIGHT
      motorSpeed1 -= for_inp / 2 + side_inp - for_inp;
      motorSpeed2 += for_inp / 2 + side_inp + for_inp;
    } else if (side_inp < -side_limt) {
      //LEFT
      motorSpeed1 += for_inp / 2 + side_inp + for_inp;
      motorSpeed2 -= for_inp / 2 + side_inp - for_inp;
    }

    Serial.println(String(motorSpeed1) + ' ' + String(motorSpeed2));
    move();
  } else {
    stop();
    delay(200);
  }
}

int mspeeds[9] = { 0, 25, 50, 100, 150, 200 };
int mdelays[9] = { 100, 150, 300, 400, 500, 600 };

void move() {

  if (motorSpeed1 > 0) {
    digitalWrite(b, LOW);
    motorWriteh(a, mdelays[idx]);

  } else {
    digitalWrite(b, LOW);
    motorWriteh(b, mdelays[idx]);
  }
  idx = 0;
  for (int x = 0; mspeeds[x] >= abs(motorSpeed2); x++) {
    idx = x;
  }
  if (motorSpeed2 > 0) {
    digitalWrite(d, LOW);
    motorWriteh(c, mdelays[idx]);
  } else {
    digitalWrite(c, LOW);
    motorWriteh(d, mdelays[idx]);
  }

  // int idx = 0;
  // for (int x1 = 0; mspeeds[x1] >= abs(motorSpeed1); x1++) {
  //   idx = x1;
  // }
  // if (motorSpeed1 > 0) {
  //   digitalWrite(b, LOW);
  //   motorWriteh(a, mdelays[idx]);

  // } else {
  //   digitalWrite(b, LOW);
  //   motorWriteh(b, mdelays[idx]);
  // }
  // idx = 0;
  // for (int x = 0; mspeeds[x] >= abs(motorSpeed2); x++) {
  //   idx = x;
  // }
  // if (motorSpeed2 > 0) {
  //   digitalWrite(d, LOW);
  //   motorWriteh(c, mdelays[idx]);
  // } else {
  //   digitalWrite(c, LOW);
  //   motorWriteh(d, mdelays[idx]);
  // }


  // code to move the motor
  // and translate motorspeed

  // int m1 = map(abs(motorSpeed1),0,5000, 0, 255);
  // int m2 = map(abs(motorSpeed1),0,5000, 0, 255);

  // if (motorSpeed1 >= 0){
  //   int m1 = map(motorSpeed1,0,5000, 0, 400);
  //   motorWrite(a, )

  // }
  // else {
  //   int m1 = map(abs(motorSpeed1),0,4000, 0, 400);
  //   motorWrite(a, )
  // }



  //====================
}

void light(int l1) {
  for (int l = 0; l < l1; l++) {
    delay(10);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(10);
  }
}

void stop() {  //Stop:
  motorSpeed1 = 0;
  motorSpeed2 = 0;
}

void motorWriteh(int p, int d) {
  digitalWrite(p, LOW);
  delay(10);
  digitalWrite(p, HIGH);
  delay(d);
  digitalWrite(p, LOW);
  delay(10);
}

// void Forward() { //Move Forward:

//   digitalWrite(a, LOW); digitalWrite(b, HIGH);
//   digitalWrite(c, LOW); digitalWrite(d, HIGH);

//   digitalWrite(13, HIGH); delay(400); digitalWrite(13, LOW);
//   delay(100);
// }

// void Backward () { //Move Backward:
//   digitalWrite(a, HIGH); digitalWrite(b, LOW);
//   digitalWrite(c, HIGH); digitalWrite(d, LOW);

//   digitalWrite(13, HIGH); delay(500); digitalWrite(13, LOW);
//   digitalWrite(13, HIGH); delay(500); digitalWrite(13, LOW);
//   delay(100);
// }

// void RightTurn() { //Turn Right:

//   digitalWrite(a, HIGH); digitalWrite(b, LOW);
//   digitalWrite(c, LOW); digitalWrite(d, HIGH);

//   digitalWrite(13, HIGH); delay(500); digitalWrite(13, LOW);
//   delay(100);

//   /*
//     motor1.run(FORWARD);                      //Drive motor1 clockwise:
//     motor1.setSpeed(motorSpeed1);              //Define motor1 speed:
//     motor2.run(FORWARD);                      //Drive motor2 clockwise:
//     motor2.setSpeed(motorSpeed1);              //Define motor2 speed:
//     motor3.run(BACKWARD);                     //Drive motor3 anti-clockwise:
//     motor3.setSpeed(motorSpeed1);              //Define motor3 speed :
//     motor4.run(BACKWARD);                     //Drive motor4 anti-clockwise:
//     motor4.setSpeed(motorSpeed1);              //Define motor4 speed:
//   */
// }
// void LeftTurn() { //Turn Left:

//   digitalWrite(a, LOW); digitalWrite(b, HIGH);
//   digitalWrite(c, HIGH); digitalWrite(d, LOW);

//   digitalWrite(13, HIGH); delay(500); digitalWrite(13, LOW);
//   delay(100);
//   /*
//     motor1.run(BACKWARD);                     //Drive motor1 anti-clockwise:
//     motor1.setSpeed(motorSpeed1);              //Define motor1 speed:
//     motor2.run(BACKWARD);                     //Drive motor2 anti-clockwise:
//     motor2.setSpeed(motorSpeed1);              //Define motor2 speed:
//     motor3.run(FORWARD);                      //Drive motor3 clockwise:
//     motor3.setSpeed(motorSpeed1);              //Define motor3 speed:
//     motor4.run(FORWARD);                      //Drive motor4 clockwise:
//     motor4.setSpeed(motorSpeed1);              //Define motor4 speed:
//   */
// }