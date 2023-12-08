#include <Arduino.h>

// Replace these with appropriate libraries for your sensors
#include "MPU6050.h"

// Define threshold values
const float delta_acc_threshold = 10.0; // g
const float delta_gyro_threshold = 50.0; // degrees/sec

// Initialize MPU6050 objects for both devices
MPU6050 device1;
MPU6050 device2;

// Variables for storing previous sensor values
float ax1_prev, ay1_prev, az1_prev;
float gx1_prev, gy1_prev, gz1_prev;
float ax2_prev, ay2_prev, az2_prev;
float gx2_prev, gy2_prev, gz2_prev;

// Variables for communication with Device 2
// (replace with your chosen communication method)
float ax2, ay2, az2;
float gx2, gy2, gz2;

void setup() {
  Serial.begin(115200);

  // Initialize MPU6050 sensors
  device1.begin();
  device2.begin();
}

void loop() {
  // Read sensor values from Device 1
  device1.read_accel(ax1, ax2, ax3);
  device1.read_gyro(gx1, gy1, gz1);

  // Read sensor values from Device 2 (replace with your communication method)
  Serial.readBytes(&ax2, sizeof(float));
  Serial.readBytes(&ay2, sizeof(float));
  Serial.readBytes(&az2, sizeof(float));
  Serial.readBytes(&gx2, sizeof(float));
  Serial.readBytes(&gy2, sizeof(float));
  Serial.readBytes(&gz2, sizeof(float));

  // Calculate absolute value of changes
  float delta_acc_1 = abs(ax1 - ax1_prev) + abs(ay1 - ay1_prev) + abs(az1 - az1_prev);
  float delta_gyro_1 = abs(gx1 - gx1_prev) + abs(gy2 - gy2_prev) + abs(gy3 - gy3_prev) ;

  float delta_acc_2 = abs(ax2 - ax2_prev) + abs(ay2 - ay2_prev) + abs(az2 - az2_prev);
  float delta_gyro_2 = abs(gx2 - gx2_prev) + abs(gy2 - gy2_prev) + abs(gz2 - gz2_prev);

  // Check for accident
  bool accident_detected = (delta_acc_1 > delta_acc_threshold) && (delta_acc_2 > delta_acc_threshold) &&
                          (delta_gyro_1 > delta_gyro_threshold) && (delta_gyro_2 > delta_gyro_threshold);

  if (accident_detected) {
    Serial.println("**Accident detected!**");
    // Trigger alarm (e.g., sound buzzer, send notification)
    // ...
  }

  // Store current values as previous values for next iteration
  ax1_prev = ax1;   ay1_prev = ay1;    az1_prev = az1;
  gx1_prev = gx1;   gy1_prev = gy1;    gz1_prev = gz1;
  
  ax2_prev = ax2;   ay2_prev = ay2;    az2_prev = az2;
  gx2_prev = gx2;   gy2_prev = gy2;    gz2_prev = gz2;

  delay(10); // adjust delay based on desired sample rate
}