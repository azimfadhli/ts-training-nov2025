#include <Wire.h>    // For I2C
#include <BH1750.h>  // For the BH1750
BH1750 lightMeter;   // Create the sensor "object"

// Pins for Ultrasonic
#define TRIG_PIN 23
#define ECHO_PIN 19

#include <thingssentralbatch.h>  //https://github.com/azimfadhli/thingssentralbatch

// WiFi credentials
const char* ssid = "MyThingssentral";
const char* password = "12345678";

// ThingsSentral configuration
const String serverURL = "http://thingssentral.io/postlong?data=";
const String userID = "00922";
const String nodeID_distance = "0092204010101";
const String nodeID_lux = "0092204010102";

ThingsSentralBatch tsBatch(serverURL, userID);

void setup() {
  Serial.begin(115200);  // 1. Start Serial for printing

  // --- BH1750 (I2C) Setup ---
  Wire.begin();        // 2. Start the I2C "bus line"
  lightMeter.begin();  // 3. Initialize the BH1750

  // --- Ultrasonic (Digital I/O) Setup ---
  pinMode(TRIG_PIN, OUTPUT);  // 4. Set Trig pin as an OUTPUT
  pinMode(ECHO_PIN, INPUT);   // 5. Set Echo pin as an INPUT

  // Connect to WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi!");
}

void loop() {
  // --- TASK 1: Read Ultrasonic ---
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2;         // Calculate distance in cm
  tsBatch.addData(nodeID_distance, distance);  // Add distance data to buffer tsBatch

  // --- TASK 2: Read BH1750 ---
  float lux = lightMeter.readLightLevel();
  tsBatch.addData(nodeID_lux, lux);  // Add lux data to buffer tsBatch

  // --- TASK 3: Report ALL Data ---
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm, ");
  Serial.print("Lux: ");

  Serial.print(lux);
  Serial.println(" lx");

  // --- TASK 4: Send data to Cloud ---
  int error = tsBatch.send2();
  if (!error) {
    Serial.println("Batch sent successfully!");
  } else {
    Serial.println("Failed to send batch! error code: " + String(error));
  }

  delay(10000);  // Wait 10 second before running the list again
}
