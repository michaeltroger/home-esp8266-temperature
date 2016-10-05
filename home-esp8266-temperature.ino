/**
Copyright 2016 Michael Troger <https://michaeltroger.com>
This file is part of Home Surveillance with Node.js.

Home Surveillance with Node.js is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Home Surveillance with Node.js is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Home Surveillance with Node.js.  If not, see <http://www.gnu.org/licenses/>.
*/
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





