// Define the pin we are using (the built-in LED)
#define LED_BUILTIN 2

void setup() {
  // 1. Configure the pin as an OUTPUT
  // This tells the ESP32 you want to send voltage OUT of this pin
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // 2. Turn the LED ON (set the pin state to HIGH)
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);  // Wait 1 second

  // 3. Turn the LED OFF (set the pin state to LOW)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);  // Wait 1 second
}
