/*
  DHT11 - Tempertature & Hummidity Sensor
  modified on 08 Sep 2020
  by Mohammad Reza Akbari @ Electropeak
  Home<iframe class="wp-embedded-content" sandbox="allow-scripts" security="restricted" style="position: absolute; clip: rect(1px, 1px, 1px, 1px);" title="&#8220;Home&#8221; &#8212; Electropeak" src="https://electropeak.com/learn/embed/#?secret=BtiHsfeMHs" data-secret="BtiHsfeMHs" width="600" height="338" frameborder="0" marginwidth="0" marginheight="0" scrolling="no"></iframe>

  Based on Adafruit Example
*/


#include "DHT.h"

#define DHTPIN 8     // Digital pin connected to DHT11

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Initializing... Please wait.");
  delay(2000);
}

void loop() {
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.println(f);

  delay(2000);
}
