// Define pins
const int trigPin = 23;

const int echoPin = 22;
const int greenLedPin = 21;
const int redLedPin = 19;
const int buzzerPin = 18;

// Variables for distance measurement
long duration;
int distance;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

  // Configure I/O pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10µs HIGH pulse to trigger the ultrasonic sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the echo pulse duration
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm (speed of sound is ~343 m/s)
  distance = duration * 0.034 / 2;

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check distance and activate components accordingly
  if (distance < 10) {
    // Object detected within 30 cm
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(buzzerPin, HIGH);
  } else {
    // Clear path
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(buzzerPin, LOW);
  }

  // Wait for a short time before next measurement
  delay(500);
}