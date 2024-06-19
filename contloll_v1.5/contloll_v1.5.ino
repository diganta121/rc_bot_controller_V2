/*Arduino bobo
  Version 1.5
*/

//include the library code:

// use pin 3, 5, 6, 9, for output
//a b c d
//variables to store channel value:

double ch3 = 2;//throttle ch3
double ch1 = 3;//steer side-side ch1
double ch2 = 4;//steer forward-back ch2


int a = 10; int b = 9;`
int c = 6; int d = 5;



int forward_lim = 25
int side_lim = 25


// vars 
int thr_inp = 0; int for_inp = 0; int side_inp = 0;

int motorSpeed1 = 0; //variable to store motor speed:
int motorSpeed2 = 0;


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


void loop()
{

  for (int x=0; x<2; x++) {
    ch1 += pulseIn(2, HIGH,3000); //speed
    ch2 += pulseIn(3, HIGH,3000); //front-back
    ch3 += pulseIn(4, HIGH,3000); //side-side
  }
  ch1 = ch1/2
  ch2 = ch2/2
  ch3 = ch3/2
  
  thr_inp = map(ch3, 1000, 2000, 0, 250); 
  For_inp = map(ch1, 1000, 2000, -20, 20);
  side_inp = map(ch2, 1000, 2000, -20, 20);

  bool enabled = (thr_inp > 1 );

  motorSpeed1 = 0;
  motorSpeed2 = 0;

  if (enabled){
    if (For_inp >= forward_lim){
      //forward
      motorSpeed1 += 2 * for_inp * thr_inp;
      motorSpeeds += 2 * for_inp * thr_inp;

    }
    else if (For_inp <= -forward_lim) {
      motorSpeed1 += 2 * thr_inp;
      motorSpeeds += 2 * thr_inp;
    }
    else{
      stop()
    }

    // sideways movement
    if (side_inp > side_lim) {
      //RIGHT
      motorSpeed1 -= (1 * thr_inp) - for_inp/2;
      motorSpeeds += (2 * thr_inp) + for_inp/2;
    }
    else if (side_inp < -side_lim) {
      //LEFT
      motorSpeed1 += (2 * thr_inp) + for_inp/2;
      motorSpeeds -= (1 * thr_inp) - for_inp/2;
    }

  move()
  }
  else{
    Stop();
    delay(200);
  }
 
}

void move(){
  // code to move the motor
  // and translate motorspeed
  
  // int m1 = map(abs(motorSpeed1),0,5000, 0, 255);
  // int m2 = map(abs(motorSpeed1),0,5000, 0, 255);

  if (motorspeed1 >= 0){
    int m1 = map(motorSpeed1,0,5000, 0, 400);
    motorWrite(a, int d)
  }
  else {
  
  }
//====================
}

void light(int l1){
  for (int l=0; l<l1; l++) { 
    delay(10);
    digitalWrite(LED_BUILTIN,HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN,LOW);
    delay(10);
  }
}

void Stop() { //Stop:
  motorSpeed1 = 0;
  motorSpeed2 = 0;

  light(1);
}

void motorWrite(int p, int d){
  digitalWrite(p,LOW);
  delay(10);
  digitalWrite(p,HIGH);
  delay(d);
  digitalWrite(p,LOW);
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