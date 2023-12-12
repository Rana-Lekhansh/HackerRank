
const float delta_acc_threshold = 10.0; // g
const float delta_gyro_threshold = 50.0; // degrees/sec


float ax1_prev, ay1_prev, az1_prev;
float gx1_prev, gy1_prev, gz1_prev;
float ax2_prev, ay2_prev, az2_prev;
float gx2_prev, gy2_prev, gz2_prev;

float ax1, ay1, az1;
float gx1, gy1, gz1;

float ax2, ay2, az2;
float gx2, gy2, gz2;


void setup() {
  
}

void loop() {
  // Read sensor values from Device 1
  device1.read_accel(ax1, ay1, az1);
  device1.read_gyro(gx1, gy1, gz1);
  device2.read_accel(ax2, ay2, az2);
  device2.read_gyro(gx2, gy2, gz2);


  float delta_acc_1 = abs(ax1 - ax1_prev) + abs(ay1 - ay1_prev) + abs(az1 - az1_prev);
  float delta_gyro_1 = abs(gx1 - gx1_prev) + abs(gy2 - gy2_prev) + abs(gy3 - gy3_prev) ;

  float delta_acc_2 = abs(ax2 - ax2_prev) + abs(ay2 - ay2_prev) + abs(az2 - az2_prev);
  float delta_gyro_2 = abs(gx2 - gx2_prev) + abs(gy2 - gy2_prev) + abs(gz2 - gz2_prev);

  bool accident_detected = (delta_acc_1 > delta_acc_threshold) && (delta_acc_2 > delta_acc_threshold) &&
                          (delta_gyro_1 > delta_gyro_threshold) && (delta_gyro_2 > delta_gyro_threshold);

  if (accident_detected) {
    Serial.println("**Accident detected!**");
    // Trigger alarm (e.g., sound buzzer, send notification)

  }


  delay(10);
}