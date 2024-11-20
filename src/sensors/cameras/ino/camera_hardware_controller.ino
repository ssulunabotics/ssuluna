#include <Servo.h>
// Control 3 servo motors for the camera arm prototype

// ---- SETUP -------------- //
// 1. Declare Pins

// servo motors
Servo servo1;
Servo servo2;
Servo servo3;


// Initialize servo angles
int angle1 = 90;
int angle2 = 90;
int angle3 = 90;

void setup() {
  // Attach servos to pins
  servo1.attach(22);
  servo2.attach(24);
  servo3.attach(26);
  servo4.attach(28);
  servo5.attach(30);
  servo6.attach(32);#include <Servo.h>
// Control 3 servo motors for the camera arm prototype

// ---- SETUP -------------- //
// 1. Declare Pins

// servo motors
Servo servo1;
Servo servo2;
Servo servo3;


// Initialize servo angles
int angle1 = 90;
int angle2 = 90;
int angle3 = 90;

void setup() {
  // Attach servos to pins
  servo1.attach(22);
  servo2.attach(24);
  servo3.attach(26);
  servo4.attach(28);
  servo5.attach(30);
  servo6.attach(32);
  
  // ------------------------------ //
  // --- [STATIC TEST ROUTINE] ---  ||
  // Works... kind of
  // ------------------------------ //

// reset servo1 for testing
  delay(500);
  servo1.write(180);#include <Servo.h>
// Control 3 servo motors for the camera arm prototype

// ---- SETUP -------------- //
// 1. Declare Pins

// servo motors
Servo servo1;
Servo servo2;
Servo servo3;


// Initialize servo angles
int angle1 = 90;
int angle2 = 90;
int angle3 = 90;

void setup() {
  // Attach servos to pins
  servo1.attach(22);
  servo2.attach(24);
  servo3.attach(26);
  servo4.attach(28);
  servo5.attach(30);
  servo6.attach(32);
  
  // ------------------------------ //
  // --- [STATIC TEST ROUTINE] ---  ||
  // Works... kind of
  // ------------------------------ //

// reset servo1 for testing
  delay(500);
  servo1.write(180);

  int tAngle = 180;
  delay(1000);
  servo1.write(tAngle);
  delay(1000);
  servo2.write(tAngle);
  delay(1000);
  servo3.write(tAngle);
  delay(1000);
  servo4.write(tAngle);

  // --- [END STATIC TESTS] --- //
 
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {

  // *** START RASPBERRY PI SERIAL COMS ***
  //  if (Serial.available() > 0) {
  //    String command = Serial.readStringUntil('\n'); // Read the command until a newline
  //
  //    // Decode the command for each servo
  //    if (command.startsWith("servo1:")) {
  //      angle1 = constrain(command.substring(7).toInt(), 0, 180);
  //      servo1.write(angle1);
  //    } else if (command.startsWith("servo2:")) {
  //      angle2 = constrain(command.substring(7).toInt(), 0, 180);
  //      servo2.write(angle2);
  //    } else if (command.startsWith("servo3:")) {
  //      angle3 = constrain(command.substring(7).toInt(), 0, 180);
  //      servo3.write(angle3);
  //    } else {
  //      Serial.println("Invalid command.");  // Send back error message
  //    }
  //  }
}


  int tAngle = 180;
  delay(1000);
  servo1.write(tAngle);
  delay(1000);
  servo2.write(tAngle);
  delay(1000);
  servo3.write(tAngle);
  delay(1000);
  servo4.write(tAngle);

  // --- [END STATIC TESTS] --- //
 
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {

  // *** START RASPBERRY PI SERIAL COMS ***
  //  if (Serial.available() > 0) {
  //    String command = Serial.readStringUntil('\n'); // Read the command until a newline
  //
  //    // Decode the command for each servo
  //    if (command.startsWith("servo1:")) {
  //      angle1 = constrain(command.substring(7).toInt(), 0, 180);
  //      servo1.write(angle1);
  //    } else if (command.startsWith("servo2:")) {
  //      angle2 = constrain(command.substring(7).toInt(), 0, 180);
  //      servo2.write(angle2);
  //    } else if (command.startsWith("servo3:")) {
  //      angle3 = constrain(command.substring(7).toInt(), 0, 180);
  //      servo3.write(angle3);
  //    } else {
  //      Serial.println("Invalid command.");  // Send back error message
  //    }
  //  }
}

  
  // ------------------------------ //
  // --- [STATIC TEST ROUTINE] ---  ||
  // Works... kind of
  // ------------------------------ //

// reset servo1 for testing
  delay(500);
  servo1.write(180);#include <Servo.h>
// Control 3 servo motors for the camera arm prototype

// ---- SETUP -------------- //
// 1. Declare Pins

// servo motors
Servo servo1;
Servo servo2;
Servo servo3;


// Initialize servo angles
int angle1 = 90;
int angle2 = 90;
int angle3 = 90;

void setup() {
  // Attach servos to pins
  servo1.attach(22);
  servo2.attach(24);
  servo3.attach(26);
  servo4.attach(28);
  servo5.attach(30);
  servo6.attach(32);
  
  // ------------------------------ //
  // --- [STATIC TEST ROUTINE] ---  ||
  // Works... kind of
  // ------------------------------ //

// reset servo1 for testing
  delay(500);
  servo1.write(180);

  int tAngle = 180;
  delay(1000);
  servo1.write(tAngle);
  delay(1000);
  servo2.write(tAngle);
  delay(1000);
  servo3.write(tAngle);
  delay(1000);
  servo4.write(tAngle);

  // --- [END STATIC TESTS] --- //
 
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {

  // *** START RASPBERRY PI SERIAL COMS ***
  //  if (Serial.available() > 0) {
  //    String command = Serial.readStringUntil('\n'); // Read the command until a newline
  //
  //    // Decode the command for each servo
  //    if (command.startsWith("servo1:")) {
  //      angle1 = constrain(command.substring(7).toInt(), 0, 180);
  //      servo1.write(angle1);
  //    } else if (command.startsWith("servo2:")) {
  //      angle2 = constrain(command.substring(7).toInt(), 0, 180);
  //      servo2.write(angle2);
  //    } else if (command.startsWith("servo3:")) {
  //      angle3 = constrain(command.substring(7).toInt(), 0, 180);
  //      servo3.write(angle3);
  //    } else {
  //      Serial.println("Invalid command.");  // Send back error message
  //    }
  //  }
}


  int tAngle = 180;
  delay(1000);
  servo1.write(tAngle);
  delay(1000);
  servo2.write(tAngle);
  delay(1000);
  servo3.write(tAngle);
  delay(1000);
  servo4.write(tAngle);

  // --- [END STATIC TESTS] --- //
 
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {

  // *** START RASPBERRY PI SERIAL COMS ***
  //  if (Serial.available() > 0) {
  //    String command = Serial.readStringUntil('\n'); // Read the command until a newline
  //
  //    // Decode the command for each servo
  //    if (command.startsWith("servo1:")) {
  //      angle1 = constrain(command.substring(7).toInt(), 0, 180);
  //      servo1.write(angle1);
  //    } else if (command.startsWith("servo2:")) {
  //      angle2 = constrain(command.substring(7).toInt(), 0, 180);
  //      servo2.write(angle2);
  //    } else if (command.startsWith("servo3:")) {
  //      angle3 = constrain(command.substring(7).toInt(), 0, 180);
  //      servo3.write(angle3);
  //    } else {
  //      Serial.println("Invalid command.");  // Send back error message
  //    }
  //  }
}
