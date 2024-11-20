// ROBOCAR DRIVE MOTORS
// -------------------------

// ---- SETUP -------------- // 
// 1. Declare Pins
int enA =   6,  in1 =   7,  in2 =   5;
int enB =   3,  in3 =   4,  in4 =   2;
int enA_2 = 11, in1_2 = 12, in2_2 = 13;
int enB_2 = 9,  in3_2 = 10, in4_2 = 8;

// ---- DATA PACKET ------- //
const byte numChars = 5;  // Only need enough space for "f255" + '\0'
char receivedChars[numChars];
boolean newData = false;

// 2. Initialize Speeds
int MotorSpeed1 = 0, MotorSpeed2 = 0, MotorSpeed3 = 0, MotorSpeed4 = 0;

void setup() {
  pinMode(enA, OUTPUT); pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
  pinMode(enA_2, OUTPUT); pinMode(enB_2, OUTPUT);
  pinMode(in1_2, OUTPUT); pinMode(in2_2, OUTPUT);
  pinMode(in3_2, OUTPUT); pinMode(in4_2, OUTPUT);
  
  Serial.begin(115200);
  
  // Run the startup test
//  startupTest();
}

void loop() {
  recvCommand();  // Receive and parse the command
  if (newData) {
    executeCommand();  // Execute the received command
    newData = false;
  }
}

// Function to receive and store the command without start/end markers
void recvCommand() {
  static byte ndx = 0;
  char rc;

  while (Serial.available() > 0 && newData == false) {
    rc = Serial.read();

    if (rc == '\n') {  // Check for newline as end of command
      receivedChars[ndx] = '\0';  // Null-terminate the string
      ndx = 0;
      newData = true;
    } else if (ndx < numChars - 1) {  // Ensure buffer isn't overrun
      receivedChars[ndx] = rc;
      ndx++;
    }
  }
}


// Function to parse and execute the command
void executeCommand() {
  char command = receivedChars[0];           // Get the command character
  int speed = atoi(&receivedChars[1]);       // Convert remaining characters to speed
  speed = constrain(speed, 0, 255);          // Ensure speed is within range

  switch (command) {
    case 'f': moveForward(speed); break;     // Forward
    case 'b': moveBackward(speed); break;    // Backward
    case 'l': turnLeft(speed); break;        // Left
    case 'r': turnRight(speed); break;       // Right
    case 's': stopMotors(); break;           // Stop
    // ! TODO: Pass in the servo with the degree e.g. (s1, speed) {degree is sent in the same decoded bytes as speed}
    case 'x': moveServo(); break;            // Camera Tilt - top servo
    case 'y': moveServo(); break;            // Camera Arm  - middle servo
    case 'z': moveServo(); break;            // Camera Pan  - bottom servo ... this one is the main one responding to inputs to look around the world
    // 
    default: Serial.println("Invalid command.");
  }
}

void startupTest() {
  int testSpeed = 100; // Set speed for the test

//
//  // Move forward for 2 seconds
//  moveForward(testSpeed);
//  delay(2000);
//
//  // Move backward for 2 seconds
//  moveBackward(testSpeed);
//  delay(2000);

  // Turn left for 2 seconds
  turnLeft(testSpeed);
  delay(2000);

  // Turn right for 2 seconds
  turnRight(testSpeed);
  delay(2000);

  // Stop motors
  stopMotors();

}


void moveForward(int speed) {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in1_2, LOW); digitalWrite(in2_2, HIGH);

  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
  digitalWrite(in3_2, HIGH); digitalWrite(in4_2, LOW);
  
  setMotorSpeeds(speed);

}

void moveBackward(int speed) {
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
  digitalWrite(in1_2, HIGH); digitalWrite(in2_2, LOW);
  
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  digitalWrite(in3_2, LOW); digitalWrite(in4_2, HIGH);
  
  setMotorSpeeds(speed);

}

void turnLeft(int speed) {
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
  digitalWrite(in1_2, LOW); digitalWrite(in2_2, HIGH);

  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  digitalWrite(in3_2, HIGH); digitalWrite(in4_2, LOW);
  setMotorSpeeds(speed);

}

void turnRight(int speed) {

  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in1_2, HIGH); digitalWrite(in2_2, LOW);

  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
  digitalWrite(in3_2, LOW); digitalWrite(in4_2, HIGH);

  setMotorSpeeds(speed);
}

void stopMotors() {
  // Fully stop the motors
  digitalWrite(in1, LOW); digitalWrite(in2, LOW);
  digitalWrite(in1_2, LOW); digitalWrite(in2_2, LOW);

  digitalWrite(in3, LOW); digitalWrite(in4, LOW);
  digitalWrite(in3_2, LOW); digitalWrite(in4_2, LOW);

  // Set motor speeds to zero
  setMotorSpeeds(0);
}

void moveServo(servo s, int degree) {
    // write to servo
    // interpolate over time
}


void setMotorSpeeds(int speed) {
  MotorSpeed1 = MotorSpeed2 = MotorSpeed3 = MotorSpeed4 = speed;
  applyMotorSpeeds();
}

void applyMotorSpeeds() {
  analogWrite(enA, MotorSpeed1);
  analogWrite(enB, MotorSpeed2);
  analogWrite(enA_2, MotorSpeed3);
  analogWrite(enB_2, MotorSpeed4);
}