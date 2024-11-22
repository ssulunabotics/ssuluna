// By:
// Alex, Jordan, Isauro, Eriberto

// motora
int enA = 6;
int in1 = 7;
int in2 = 5;
// motorb
int enB = 3;
int in3 = 4;
int in4 = 2;
// motorc
int enA_2 = 11;
int in1_2 = 12;
int in2_2 = 13;
// motord
int enB_2 = 9;
int in3_2 = 10;
int in4_2 = 8;

//joystick variable with inputs
int joyVert = A0; // Vertical  
int joyHorz = A1; // Horizontal

// motor Speed Values - Start at zero
int MotorSpeed1 = 0;
int MotorSpeed2 = 0;
int MotorSpeed3 = 0;
int MotorSpeed4 = 0;

// Joystick Values - Start at 512 (middle position)
int joyposVert = 512;
int joyposHorz = 512;

// Deadzone threshold
int deadzone = 50;

void setup()
{
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(enA_2, OUTPUT);
  pinMode(enB_2, OUTPUT);
  pinMode(in1_2, OUTPUT);
  pinMode(in2_2, OUTPUT);
  pinMode(in3_2, OUTPUT);
  pinMode(in4_2, OUTPUT);
   
  // Start with motors disabled and direction forward
  digitalWrite(enA, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  digitalWrite(enB, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  digitalWrite(enA_2, LOW);
  digitalWrite(in1_2, HIGH);
  digitalWrite(in2_2, LOW);
  
  digitalWrite(enB_2, LOW);
  digitalWrite(in3_2, HIGH);
  digitalWrite(in4_2, LOW);

  Serial.begin(9600);  // Initialize serial communication for debugging
}

void loop() {
  // Read the Joystick X and Y positions
  joyposVert = analogRead(joyVert); 
  joyposHorz = analogRead(joyHorz);

  // Handle forward/backward movement based on vertical joystick position
  if (joyposVert < 512 - deadzone)  // Backward motion
  {
    // Set all motors to backward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    digitalWrite(in1_2, HIGH);
    digitalWrite(in2_2, LOW);
    digitalWrite(in3_2, LOW);
    digitalWrite(in4_2, HIGH);

    // Adjust motor speeds for backward movement
    MotorSpeed1 = map(512 - joyposVert, 0, 512, 0, 255);  // Map reverse speed
    MotorSpeed2 = MotorSpeed1;
    MotorSpeed3 = MotorSpeed1;
    MotorSpeed4 = MotorSpeed1;
  }
  else if (joyposVert > 512 + deadzone)  // Forward motion
  {
    // Set all motors to forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

    digitalWrite(in1_2, LOW);
    digitalWrite(in2_2, HIGH);
    digitalWrite(in3_2, HIGH);
    digitalWrite(in4_2, LOW);

    // Adjust motor speeds for forward movement
    MotorSpeed1 = map(joyposVert, 512, 1023, 0, 255);  // Map forward speed
    MotorSpeed2 = MotorSpeed1;
    MotorSpeed3 = MotorSpeed1;
    MotorSpeed4 = MotorSpeed1;
  }
  else  // Joystick in the middle, stop the motors
  {
    MotorSpeed1 = 0;
    MotorSpeed2 = 0;
    MotorSpeed3 = 0;
    MotorSpeed4 = 0;
  }

  // Handle turning based on horizontal joystick position
  if (joyposHorz < 512 - deadzone)  // Left turn
  {
    // Slow down left side motors and speed up right side motors for a right turn
    digitalWrite(in1, LOW);   // Left motors backward
    digitalWrite(in2, HIGH);
    digitalWrite(in1_2, LOW);
    digitalWrite(in2_2, HIGH);

    digitalWrite(in3, HIGH);  // Right motors forward
    digitalWrite(in4, LOW);
    digitalWrite(in3_2, HIGH);
    digitalWrite(in4_2, LOW);

    // Adjust motor speeds for left turn
    int turningSpeed = map(512 - joyposHorz, 0, 512, 0, 255);
    MotorSpeed1 = turningSpeed;
    MotorSpeed2 = turningSpeed;
    MotorSpeed3 = turningSpeed;
    MotorSpeed4 = turningSpeed;
  }
  else if (joyposHorz > 512 + deadzone)  // Right turn
  {

  // Slow down right side motors and speed up left side motors for a left turn
    digitalWrite(in1, HIGH);   // Left motors forward
    digitalWrite(in2, LOW);
    digitalWrite(in1_2, HIGH);
    digitalWrite(in2_2, LOW);

    digitalWrite(in3, LOW);    // Right motors backward
    digitalWrite(in4, HIGH);
    digitalWrite(in3_2, LOW);
    digitalWrite(in4_2, HIGH);

    // Adjust motor speeds for right turn
    int turningSpeed = map(joyposHorz, 512, 1023, 0, 255);
    MotorSpeed1 = turningSpeed;
    MotorSpeed2 = turningSpeed;
    MotorSpeed3 = turningSpeed;
    MotorSpeed4 = turningSpeed;
  }

  // Prevent low-speed buzzing
  if (MotorSpeed1 < 8) MotorSpeed1 = 0;
  if (MotorSpeed2 < 8) MotorSpeed2 = 0;
  if (MotorSpeed3 < 8) MotorSpeed3 = 0;
  if (MotorSpeed4 < 8) MotorSpeed4 = 0;

  // Set the motor speeds using PWM
  analogWrite(enA, MotorSpeed1);
  analogWrite(enB, MotorSpeed2);
  analogWrite(enA_2, MotorSpeed3);
  analogWrite(enB_2, MotorSpeed4);

  // Debugging output for joystick and motor speeds
  Serial.print("Joystick Vertical: ");
  Serial.println(joyposVert);
  Serial.print("Joystick Horizontal: ");
  Serial.println(joyposHorz);
  Serial.print("Motor Speed: ");
  Serial.println(MotorSpeed1);
}
