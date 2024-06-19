

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 bps
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  
}

void loop() {
  
  double ch1 = pulseIn(2, HIGH, 4000);  //speed
  double ch2 = pulseIn(3, HIGH, 4000);  //front-back
  double ch3 = pulseIn(4, HIGH, 4000);  //side-side
  
  int channel1Value = analogRead(3); 
  int channel2Value = analogRead(4); 

  Serial.print("ch: ");
  Serial.print(ch1);
  Serial.print(' ');
  Serial.print(ch2);
  Serial.print(' ');
  Serial.print(ch3);
  Serial.print(' ');

  Serial.print("Analog ");
  Serial.print(channel1Value);
  Serial.print(' ');
  Serial.println(channel2Value);

  delay(100); // Wait for 100ms before reading again
}
