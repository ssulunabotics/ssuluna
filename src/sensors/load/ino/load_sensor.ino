#include "HX711.h"

// Pin definitions for HX711
#define DT 2   // Data pin connected to HX711 DT
#define SCK 3  // Clock pin connected to HX711 SCK

HX711 scale;

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
}

void loop() {
  // Print the weight in pounds
  if (scale.is_ready()) {
    float weight = scale.get_units(10); // Average over 10 readings for stability
    float weight_pounds = weight / 8053.59237; // Convert grams to pounds
    Serial.print("Weight: ");
    Serial.print(weight_pounds, 4); // Print with 4 decimal places
    Serial.println(" pounds");
  } else {
    Serial.println("HX711 not found.");
  }
  delay(500);
}