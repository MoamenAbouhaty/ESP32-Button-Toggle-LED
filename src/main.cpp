/*
  Project Name : ESP32-Button-Toggle-LED
  Author       : Moamen Abouhaty
  Version      : 1.0.0
  Date         : 2026
  Description  :
    Press the button once to turn ON the LED.
    Press the button again to turn OFF the LED.

  Hardware:
    - ESP32 DevKit V1
    - Push Button (using internal pull-up)
    - 5mm LED with 220 ohm resistor

  Copyright:
    © 2026 Moamen Abouhaty. All rights reserved.
*/

#include <Arduino.h>

// Define pin numbers
#define LED_PIN     2
#define BUTTON_PIN  4

// Variables to store button and LED states
bool ledState = false;          // Current LED state (ON/OFF)
bool lastButtonState = HIGH;    // Previous button state
bool currentButtonState;

// Setup function runs once when ESP32 starts
void setup() {
  pinMode(LED_PIN, OUTPUT);                 // Set LED pin as output
  pinMode(BUTTON_PIN, INPUT_PULLUP);        // Enable internal pull-up resistor

  digitalWrite(LED_PIN, LOW);               // Turn LED OFF initially
}

// Loop function runs continuously
void loop() {

  // Read the current button state
  currentButtonState = digitalRead(BUTTON_PIN);

  // Detect button press (state change from HIGH to LOW)
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    
    // Toggle LED state
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);

    // Simple debounce delay
    delay(200);
  }

  // Save the current button state for next loop
  lastButtonState = currentButtonState;
}