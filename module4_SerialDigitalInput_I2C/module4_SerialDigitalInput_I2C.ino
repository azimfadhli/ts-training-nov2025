// 1. Include the libraries (our "translator" & "bus driver")
#include <Wire.h>
#include <BH1750.h>

// 2. Create an "object" for our sensor
BH1750 lightMeter;

void setup() {
  Serial.begin(115200);

  // 3. Start the I2C "bus line"
  Wire.begin();  // (You can also specify pins: Wire.begin(SDA_PIN, SCL_PIN))

  // 4. Find the sensor at its address (0x23) and set its mode
  lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE, 0x23, &Wire);
}

void loop() {
  // 5. Ask the library to get the data
  if (lightMeter.measurementReady()) {
    float lux = lightMeter.readLightLevel();  // The library does all the work!

    Serial.print("Ambient Light: ");
    Serial.print(lux);
    Serial.println(" lx");
  }
  delay(1000);
}
