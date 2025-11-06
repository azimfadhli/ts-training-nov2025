#include <thingssentralbatch.h>  //https://github.com/azimfadhli/thingssentralbatch

// WiFi credentials
const char* ssid = "MyThingssentral";
const char* password = "12345678";

// ThingsSentral configuration
const String serverURL = "http://thingssentral.io/postlong?data=";
const String userID = "00922";
const String nodeID = "0092204010101";

ThingsSentralBatch tsBatch(serverURL, userID);

void setup() {
  Serial.begin(115200);

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
  // generate random float number
  float dummyData = random(1, 1234) / 100.0;
  Serial.println("Dummy data generated: " + String(dummyData));

  // Add data to the batch
  tsBatch.addData(nodeID, dummyData);

  // Send the batch
  int error = tsBatch.send2();
  if (!error) {
    Serial.println("Batch sent successfully!");
  } else {
    Serial.println("Failed to send batch! error code: " + String(error));
  }

  // Wait 10s before next transmission
  delay(10000);
}