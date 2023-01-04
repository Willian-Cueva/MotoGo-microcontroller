#include <BluetoothSerial.h>
BluetoothSerial SerialBT;
//const uint8_t led = 2; // led integrado gpio 2 para mi devkit
const String deviceName = "Moto DesDevKit";
byte dataRx;
/* Check if Bluetooth configurations are enabled in the SDK */
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
void setup() {
  Serial.begin(115200);
  SerialBT.begin(deviceName);
  Serial.println(deviceName + " listo!...");
}
void loop() {
  serialEvent();
  if (dataRx == 'A') {
    const String act = "Escanear huella";
    Serial.println(act);
    SerialBT.println(act);
  } else if (dataRx == 'B') {
    const String act = "Comprobar huella q se yo xd";
    Serial.println(act);
    SerialBT.println(act);
  }

  //    digitalWrite(led, HIGH) ;
}// eof loop
void serialEvent() {
  if (SerialBT.available())
  {
    dataRx = SerialBT.read();
    Serial.write(dataRx);
  }
}
