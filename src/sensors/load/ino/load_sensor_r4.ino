// Display weight on Arduino built in LED on r4
// Load sensor for sand bucket

#include "HX711.h"

// Necessary for display on built in LED
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

// Pin definitions for HX711 load sensor chip
#define DT 2   // Data pin connected to HX711 DT
#define SCK 3  // Clock pin connected to HX711 SCK

HX711 scale;
ArduinoLEDMatrix matrix;

// Calibration factor (this value needs to be calibrated)
float calibration_factor = -10000.0; // Adjust this value during calibration

void setup() {
  Serial.begin(9600);
  Serial.println("HX711 Calibration");

  // Initialize the HX711 scale
  scale.begin(DT, SCK);
  
  // Optional: Tare the scale to set the current weight as zero
  Serial.println("Taring... Please ensure the scale is empty.");
  scale.set_scale(); // Set scale to an initial default
  scale.tare();      // Reset the scale to zero
  Serial.println("Tare complete.");
  
  Serial.println("Place a known weight on the scale and adjust the calibration factor.");
  delay(2000);

  // Initialize the LED matrix
  matrix.begin();
}

void loop() {
  // Print the weight in pounds
  if (scale.is_ready()) {
    float weight = scale.get_units(10); // Average over 10 readings for stability
    float weight_pounds = weight / 8053.59237; // Convert grams to pounds
    Serial.print("Weight: ");
    Serial.print(weight_pounds, 4); // Print with 4 decimal places
    Serial.println(" pounds");

    // Convert weight to string with 2 decimal places
    char weight_str[8];
    dtostrf(weight_pounds, 4, 1, weight_str);

    // ------------------------- //
    // DISPLAY on Arduino LED
    // ------------------------- //
    matrix.beginDraw();
    matrix.stroke(0xFFFFFFFF);
    matrix.textScrollSpeed(100);
    matrix.textFont(Font_4x6);
    matrix.beginText(0, 1, 0xFFFFFF);
    matrix.println(weight_str);
    matrix.endText(SCROLL_LEFT);
    matrix.endDraw();
  } else {
    Serial.println("HX711 not found.");
  }
  delay(500);
}
