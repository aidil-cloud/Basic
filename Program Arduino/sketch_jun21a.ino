#include <Wire.h>
#include "MAX30105.h"

MAX30105 particleSensor;

void setup() {
  Serial.begin(9600);
  delay(1000);

  // Inisialisasi sensor
  if (!particleSensor.begin(Wire, I2C_SPEED_STANDARD)) {
    Serial.println("Sensor MAX30102 tidak terdeteksi. Cek koneksi!");
    while (1);
  }

  // Konfigurasi sensor
  particleSensor.setup(); 
  particleSensor.setPulseAmplitudeRed(0x0A);    // LED merah
  particleSensor.setPulseAmplitudeIR(0x0A);     // LED inframerah
}

void loop() {
  long irValue = particleSensor.getIR();    // Sinyal inframerah (IR)
  long redValue = particleSensor.getRed();  // Sinyal LED merah

  // Tampilkan nilai ke Serial Monitor
  Serial.print("IR: ");
  Serial.print(irValue);
  Serial.print("\tRed: ");
  Serial.println(redValue);

  delay(500);
}
