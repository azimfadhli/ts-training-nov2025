#include <WiFi.h>
#include <HTTPClient.h>

// --- START: USER CONFIGURATION ---
/* const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
 */
const char* ssid = "MyThingssentral";
const char* password = "12345678";

/* * IMPORTANT: You must change this to your specific User ID.
 * The example in the manual uses "00691".
 */
const String YOUR_USER_ID = "00691";
// --- END: USER CONFIGURATION ---


void setup() {
  Serial.begin(115200);

  // 1. Connect to WiFi
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if WiFi is still connected
  if (WiFi.status() == WL_CONNECTED) {

    // -----------------------------------------------------------------
    //  EXAMPLE 1: POSTING A SINGLE NODE VALUE
    //  Based on: http://thingssentral.io/postlong?data=userid|00691@0069101010101|1
    // -----------------------------------------------------------------
    Serial.println("\n--- EXAMPLE 1: Sending SINGLE Node Value ---");

    // 1a. Define data for a single node
    String nodeID_1 = "0069101010101";
    String value_1 = "1";

    // 1b. Build the URL string for a single node
    String url_single = "http://thingssentral.io/postlong?data=userid|" + YOUR_USER_ID;
    url_single += "@" + nodeID_1 + "|" + value_1;

    Serial.print("Final URL for SINGLE node: ");
    Serial.println(url_single);

    // 1c. Send the HTTP request
    HTTPClient http_single;
    http_single.begin(url_single);
    int httpCode_single = http_single.GET();

    // 1d. Check the response
    if (httpCode_single > 0) {
      String payload = http_single.getString();
      Serial.println("Request successful! Server response:");
      Serial.println(payload);
    } else {
      Serial.printf("Request failed. Server returned HTTP code: %d\n", httpCode_single);
    }
    http_single.end();  // Close the connection


    // Wait 15 seconds before the next example
    Serial.println("\nWaiting 15 seconds...");
    delay(15000);


    // -----------------------------------------------------------------
    //  EXAMPLE 2: POSTING MULTIPLE NODE VALUES
    //  Based on the 3-node example in the manual.
    // -----------------------------------------------------------------
    Serial.println("\n--- EXAMPLE 2: Sending MULTIPLE Node Values ---");

    // 2a. Define data for multiple nodes
    String multi_nodeID_1 = "0069101010101";
    String multi_value_1 = "1";

    String multi_nodeID_2 = "0069101010102";
    String multi_value_2 = "2";

    String multi_nodeID_3 = "0069101010103";
    String multi_value_3 = "3";

    // 2b. Build the URL string for multiple nodes
    String url_multi = "http://thingssentral.io/postlong?data=userid|" + YOUR_USER_ID;
    url_multi += "@" + multi_nodeID_1 + "|" + multi_value_1;  // Add Node 1
    url_multi += "@" + multi_nodeID_2 + "|" + multi_value_2;  // Add Node 2
    url_multi += "@" + multi_nodeID_3 + "|" + multi_value_3;  // Add Node 3

    Serial.print("Final URL for MULTIPLE nodes: ");
    Serial.println(url_multi);

    // 2c. Send the HTTP request
    HTTPClient http_multi;
    http_multi.begin(url_multi);
    int httpCode_multi = http_multi.GET();

    // 2d. Check the response
    if (httpCode_multi > 0) {
      String payload = http_multi.getString();
      Serial.println("Request successful! Server response:");
      Serial.println(payload);
    } else {
      Serial.printf("Request failed. Server returned HTTP code: %d\n", httpCode_multi);
    }
    http_multi.end();  // Close the connection

  } else {
    Serial.println("WiFi is disconnected.");
  }

  // Wait 30 seconds before running the loop again
  Serial.println("\n--- Both examples complete. Waiting 30 seconds... ---");
  delay(30000);
}