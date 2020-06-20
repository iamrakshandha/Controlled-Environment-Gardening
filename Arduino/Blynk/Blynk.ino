#define BLYNK_PRINT DebugSerial
#define BLYNK_PRINT SwSerial
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); 
SoftwareSerial SwSerial(10, 11); 
#include <BlynkSimpleStream.h>
#include <DHT.h>

char authentication[] = "-xkZ5RSNb3L1KsWcExQrpMp7brwzqB7A";

#define DHTPIN 2    
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 
  if (isnan(h) || isnan(t)) {
    SwSerial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
}


void setup()
{  
  DebugSerial.begin(9600);
  SwSerial.begin(9600);
  Serial.begin(9600);
  Blynk.begin(Serial, authentication);
  dht.begin();
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
