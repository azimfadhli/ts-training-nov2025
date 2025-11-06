// Define which GPIO pin is connected to the sensor's Analog Out (A0)
// GPIO 34 is a good example of an ADC-capable pin.
#define MOISTURE_PIN 34

void setup() {
  Serial.begin(115200);

  // We don't need pinMode() for analogRead() on ESP32
}

void loop() {
  // 1. Read the ADC-capable pin.
  // This returns a raw value between 0 (dry) and 4095 (wet)
  // (Note: some sensors are inverted)
  int rawValue = analogRead(MOISTURE_PIN);

  Serial.print("Raw ADC Value: ");
  Serial.println(rawValue);

  // 2. (Optional) Convert the raw value to a user-friendly percentage
  // We use the map() function to re-scale the number
  int percentage = map(rawValue, 0, 4095, 0, 100);

  Serial.print("Moisture Level: ");
  Serial.print(percentage);
  Serial.println("%");

  delay(1000);
}
