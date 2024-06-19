int channel1Pin = 0; // The analog pin used to read channel 1
int channel2Pin = 1; // The analog pin used to read channel 2

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 bps
}

void loop() {
  int channel1Value = analogRead(channel1Pin); // Read the value of channel 1
  int channel2Value = analogRead(channel2Pin); // Read the value of channel 2

  // Print the values to the serial monitor
  Serial.print("Channel 1 value: ");
  Serial.println(channel1Value);
  Serial.print("Channel 2 value: ");
  Serial.println(channel2Value);

  delay(100); // Wait for 100ms before reading again
}
