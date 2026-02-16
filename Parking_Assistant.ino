/**
 * Project: Smart Automotive Parking Assistant (v1.0)
 * Description: An intelligent system that calculates object proximity 
 * and provides dynamic audio-visual feedback to simulate parking sensors.
 * Author: [Your Name/GitHub Username]
 */

// Pin Configuration
const int trigPin = 12;    // Ultrasonic sensor trigger pin (Pulse transmitter)
const int echoPin = 11;    // Ultrasonic sensor echo pin (Pulse receiver)
const int ledPin = 9;      // Visual alert output pin (LED)
const int buzzerPin = 8;   // Audible alert output pin (Piezo Buzzer)

void setup() {
  // Initialize communication and pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Serial communication for real-time telemetry monitoring
  Serial.begin(9600);
}

void loop() {
  long duration, distance;

  // Clear the trigger pin to ensure a clean ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10-microsecond high-frequency sound pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Calculate the time taken for the pulse to bounce back
  duration = pulseIn(echoPin, HIGH);
  
  // Convert travel time into distance (cm)
  // Formula: (Time / 2) / 29.1 based on the speed of sound
  distance = (duration / 2) / 29.1;

  // Output distance data to the Serial Monitor
  Serial.print("Proximity: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Logic: Activate alert sequence if an object is within the 30cm threshold
  if (distance < 30) {
    digitalWrite(ledPin, HIGH); // Trigger visual alert
    
    // Dynamic Feedback Algorithm:
    // Decreases delay based on distance, creating faster beeps as proximity closes.
    tone(buzzerPin, 1000);       // Execute 1kHz frequency tone
    delay(distance * 10);        // Dynamic interval timing
    noTone(buzzerPin);           // End tone
    delay(distance * 10);        // Dynamic interval timing
  } 
  else {
    // Reset all alert indicators when clear of proximity threshold
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }
}
