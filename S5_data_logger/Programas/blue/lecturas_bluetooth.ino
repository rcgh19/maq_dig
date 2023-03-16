#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif
#include "Adafruit_BMP085.h"
// LOGUEAR LA INF DEL SENSOR BAROMETRICO LDR
#define LED_PIN 33
#define LDR_PIN 35


//File readings;
Adafruit_BMP085 bmp;
BluetoothSerial SerialBT;
char payload [80];



void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN,OUTPUT);
  Serial.begin(115200);
  bmp.begin();
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  //if(!SD.begin()){
  //  Serial.println("Card Mount Failed");
  //  return;    
  //}


}

void loop() {
  //hacer paylo de mlecturas
  sprintf(payload, "%6.2f,%3.2f,%d",
          bmp.readPressure(),
          bmp.readTemperature(),
          analogRead(LDR_PIN));  
  digitalWrite(LED_PIN,HIGH);
    //readings = SD.open("/lecturas_sensor.csv",FILE_APPEND);
    // write, open y read abrir archivo  
    //readings.println(payload);
    //readings.close();
    SerialBT.println(payload);
    Serial.println(payload);
  digitalWrite(LED_PIN,LOW);

  delay(500);  
}
