# Smart Automotive Parking Assistant (v1.0)

This project features a real-time proximity alert system designed to simulate modern automotive parking sensors. It transforms raw ultrasonic data into dynamic audio-visual feedback.

## Project Features
- **Adaptive Pulse Algorithm:** The system calculates object distance using the HC-SR04 ultrasonic sensor and adjusts feedback frequency in real-time.
- **Dynamic Audio Feedback:** As proximity decreases, the Piezo buzzer's beep intervals shorten, mimicking a professional vehicle parking assistant.
- **Visual Alert System:** A high-intensity LED provides immediate visual confirmation when an object enters the danger zone (30cm).

## Hardware Components
- **Microcontroller:** Arduino Uno
- **Sensor:** HC-SR04 Ultrasonic Sensor
- **Output 1:** Piezo Buzzer (Audio Feedback)
- **Output 2:** 5mm LED (Visual Feedback)
- **Chassis:** Custom-built lightweight prototype housing for sensor alignment.

## Implementation Details
The system utilizes the pulseIn() function to measure the duration of sound wave travel. Distance is computed based on the speed of sound in air (approx. 343 m/s).

## Project Media
