#include <Servo.h>

#define trigPin 5
#define echoPin 2

Servo servo;

void setup() {
  // Initialize the servo
  servo.attach(4); // Attach the servo to pin 4

  // Set the pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  long duration, distance;

  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance in cm
  distance = (duration / 2) / 29.1;

  // Print the distance for debugging
  Serial.print("Distance: ");
  Serial.println(distance);

  // Check distance and control servo
  if (distance < 5) {
    Serial.println("The distance is less than 5 cm");
    servo.write(90); // Move servo to 90 degrees
  } else {
    servo.write(0); // Move servo to 0 degrees (or other angle as needed)
  }

  delay(500); // Wait before the next reading
}
