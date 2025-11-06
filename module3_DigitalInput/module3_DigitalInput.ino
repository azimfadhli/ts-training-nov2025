// Define the pin for the built-in button
#define BUTTON_PIN 0

void setup() {
  Serial.begin(115200);  // Start serial for printing

  // 1. Configure the pin as an INPUT
  //    INPUT_PULLUP activates the internal "default HIGH" resistor.
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // 2. Read the pin's state
  int buttonState = digitalRead(BUTTON_PIN);

  // 3. Print the state to the Serial Monitor
  //    - Because of PULLUP, pin is HIGH when not pressed.
  //    - Pin is pulled LOW (0) when you press the button.
  Serial.println(buttonState);

  delay(50);  // Small delay to prevent spam
}
