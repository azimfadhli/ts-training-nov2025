#include <Wire.h>    // For I2C
#include <BH1750.h>  // For the BH1750 || search for "BH1750" by Christopher https://github.com/claws/BH1750
BH1750 lightMeter;   // Create the sensor "object"

// Pins for Ultrasonic
#define TRIG_PIN 23
#define ECHO_PIN 19

void setup() {
  Serial.begin(115200);  // 1. Start Serial for printing

  // --- BH1750 (I2C) Setup ---
  Wire.begin();        // 2. Start the I2C "bus line"
  lightMeter.begin();  // 3. Initialize the BH1750

  // --- Ultrasonic (Digital I/O) Setup ---
  pinMode(TRIG_PIN, OUTPUT);  // 4. Set Trig pin as an OUTPUT
  pinMode(ECHO_PIN, INPUT);   // 5. Set Echo pin as an INPUT
}

void loop() {
  // --- TASK 1: Read Ultrasonic ---
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2;  // Calculate distance in cm

  // --- TASK 2: Read BH1750 ---
  float lux = lightMeter.readLightLevel();

  // --- TASK 3: Report ALL Data ---
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm, ");
  Serial.print("Lux: ");

  Serial.print(lux);
  Serial.println(" lx");

  delay(1000);  // Wait 1 second before running the list again
}
