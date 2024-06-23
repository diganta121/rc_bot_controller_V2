
double inp[3];

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 bps
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  
}

void loop() {
  inp[0] = pulseIn(2, HIGH, 2500);
  inp[1] = pulseIn(3, HIGH, 2500);
  inp[2] = pulseIn(4, HIGH, 2500);
  


  Serial.print("ch: ");
  Serial.print(inp[0]);
  Serial.print(' ');
  Serial.print(inp[1]);
  Serial.print(' ');
  Serial.print(inp[2]);
  Serial.print('\n');

  delay(100); // Wait for 100ms before reading again
}
