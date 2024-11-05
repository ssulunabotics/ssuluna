// By Justin Amstadt
// Sends a serial message back that prints the distance

const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); // Reads echo pin

  distance = duration * 0.034 / 2.0; // Calc distance

  Serial.println(distance);

  delay(100); // Small delay for readability
}
