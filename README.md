# home-esp8266-temperature

This is an Arduino project for use with the ESP8266 in form of a NodeMCU. It is part of the DIY home surveillance with a Raspberry Pi as server https://github.com/michaeltroger/home

The DHT sensor library for Arduino is needed
https://github.com/adafruit/DHT-sensor-library

create a file named `wificonf.h` with your wifi login credentials like:

`const char[] WIFI_SSID = "your-ssid";
const char[] WIFI_PSK = "your password";`
