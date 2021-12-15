#include <VL53L0X.h>
#include <Wire.h>
VL53L0X tof_sensor;
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  tof_sensor.setTimeout(1000);
  if (tof_sensor.init() == 0)
  {
    Serial.println("Не удалось обнаружить и инициализировать датчик!");
    while (1) {}
  }
  tof_sensor.startContinuous();
  
}

int distance = 0;
void loop() {
  // put your main code here, to run repeatedly:
  distance = tof_sensor.readRangeContinuousMillimeters();
  if (tof_sensor.timeoutOccurred()) { 
    Serial.println(" ТАЙМАУТ"); 
  } else {
    Serial.println(distance);
  }
}
