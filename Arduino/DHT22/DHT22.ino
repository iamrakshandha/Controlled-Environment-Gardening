#include "DHT.h"
#define DHTPIN 2     
#define DHTTYPE DHT22  
DHT dht(DHTPIN, DHTTYPE);
void setup() 
{
  Serial.begin(9600); 
  Serial.println("Weather Monitoring");
  dht.begin();
}

void loop() 
{
  delay(2000);
  float temperatureinC = dht.readTemperature();
  float humidity = dht.readHumidity();
  float temperatureinF = dht.readTemperature(true);
  float heatIndex = dht.computeHeatIndex(temperatureinF,humidity);
  Serial.print("Temperature in Celcius: "); 
  Serial.print(temperatureinC);
  Serial.print(" Temperature in Fahrenheit: ");
  Serial.print(temperatureinF);
  Serial.print(" Humidity: "); 
  Serial.print(humidity);
  Serial.print(" Heat Index: ");
  Serial.println(heatIndex);
}
