// Runs ONCE at boot or reset
void setup() {
  // Initialize serial communication at 115200 bits per second (baud)
  Serial.begin(115200);
}

// Runs continuously in a loop AFTER setup() finishes
void loop() {
  // Print a string to the serial port, followed by a new line
  Serial.println("Hello World!");

  // Pause execution for 1000 milliseconds (1 second)
  delay(1000);
}
