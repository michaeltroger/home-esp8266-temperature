#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "wificonf.h"

ESP8266WebServer server(80);
DHT dht(D5, DHT22); 

float hum; 
float temp; 

void handleRoot() {
  // read the data from the sensor
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  
  server.send(200, "text/json", "{\"hum\":"+String(hum)+",\"temp\":"+String(temp)+"}");
}

void setup()
{
  // connect to the WIFI
  WiFi.begin(WIFI_SSID, WIFI_PSK);
  // init the sensor
  dht.begin();
  // wait a moment for WIFI connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  server.on("/", handleRoot);
  server.begin();
}

void loop()
{
  server.handleClient();
}





