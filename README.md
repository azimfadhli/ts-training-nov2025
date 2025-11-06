# ESP32 IoT Training (November 2025)

This repository contains all the sample code and resources for the ESP32 IoT training session, focused on connecting sensors to the **ThingsSentral** platform.

The training guides you from the absolute basics of ESP32 programming to building a complete IoT device that reads from multiple sensors and sends live data to the cloud.

## 🚀 Key Learning Objectives

  * Write, compile, and upload your first ESP32 program (Hello World).
  * Control digital outputs (blinking an LED).
  * Read digital inputs (reading a button).
  * Understand and use analog inputs (reading a variable signal).
  * Communicate with complex sensors using the **I2C protocol (BH1750 Light Sensor)**.
  * Integrate multiple sensors (I2C + Digital I/O) into a single project.
  * Connect your ESP32 to a local WiFi network.
  * Send both "dummy" and *real* sensor data to the ThingsSentral IoT platform.

## ⚙️ Hardware & Software Requirements

### Hardware

  * ESP32 Development Kit (e.g., ESP32-WROOM-32)
  * **BH1750** Ambient Light Sensor
  * **Ultrasonic Sensor** (HC-SR04 or similar 3V-5.5V model)
  * Breadboard
  * Jumper Wires
  * Micro USB Cable

### Software

  * [Arduino IDE](https://www.arduino.cc/en/software)
  * ThingsSentral Account
  * **Required Arduino Libraries:**
      * [`BH1750.h`](https://github.com/claws/BH1750)
      * [`thingssentralbatch.h`](https://github.com/azimfadhli/thingssentralbatch)

## Wiring Diagram

All modules build towards the final circuit. Refer to this diagram for the complete wiring of the BH1750 and Ultrasonic sensors.

![alt text](https://github.com/azimfadhli/ts-training-nov2025/blob/main/ts%20training%20circuit%20diagram.png)

## 📁 Repository Structure

This repository is structured by modules. Each folder contains the complete `.ino` sketch for that specific lesson.

  * **`module1_HelloWorld`**

      * Your first program. Prints "Hello World\!" to the Serial Monitor.

  * **`module2_DigitalOutput`**

      * Blinks the built-in LED. Demonstrates `pinMode(OUTPUT)` and `digitalWrite()`.

  * **`module3_DigitalInput`**

      * Reads the built-in button. Demonstrates `pinMode(INPUT_PULLUP)` and `digitalRead()`.

  * **`module4_SerialDigitalInput_I2C`**

      * Reads ambient light (lux) from the **BH1750 sensor** using the I2C protocol (`Wire.h`).

  * **`module5_AnalogInput`**

      * (Theory/Example) Shows how to read a variable voltage using `analogRead()`.

  * **`module6_MultiSensorIntegration`**

      * A combined sketch that reads from *both* the **BH1750** and the **Ultrasonic sensor** at the same time and prints both values to the Serial Monitor.

  * **`module8_ConnectingToTheCloud_DummyData`**

      * Connects the ESP32 to WiFi and sends a *random number* to ThingsSentral. This verifies your cloud connection.

  * **`module9_SendingRealSensorData`**

      * The final project\! This code reads real data from both sensors and sends it to your ThingsSentral project.

> **Note:** Module 7 (Platform Setup) and Module 10 (Dashboarding) are activities performed on the ThingsSentral website and do not have dedicated ESP32 code.

## Usage

1.  **Clone or Download:** Get a local copy of this repository.
2.  **Install Libraries:** Open the Arduino IDE and install the required libraries listed above via the Library Manager.
3.  **Open & Upload:** Open the `.ino` file for the module you are on.
4.  **Update Credentials:** For Modules 8 and 9, you **must** update the following variables with your own credentials:
    ```c
    const char* ssid = "Your_WiFi_Name";
    const char* password = "Your_WiFi_Password";
    const char* userID   = "Your_ThingsSentral_User_ID";
    const char* nodeID   = "Your_ThingsSentral_Node_ID";
    ```
5.  **Run:** Upload the code and open the Serial Monitor (Baud Rate: 115200) to see the output.
