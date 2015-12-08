#include <SPI.h>
#include <Adafruit_CC3000.h>
#include <ccspi.h>
#include <Client.h>
#include <Temboo.h>
#include "TembooAccount.h" // Contains Temboo account information

#define ADAFRUIT_CC3000_IRQ 3
#define ADAFRUIT_CC3000_VBAT 5
#define ADAFRUIT_CC3000_CS 10

Adafruit_CC3000 cc3k = Adafruit_CC3000(ADAFRUIT_CC3000_CS, ADAFRUIT_CC3000_IRQ, ADAFRUIT_CC3000_VBAT);

Adafruit_CC3000_Client client;

// define variables
int redValue;
int greenValue;
int blueValue;

// Define Pins
#define RED 3
#define GREEN 4
#define BLUE 6

void setup() {
  Serial.begin(9600);
  delay(4000);
  connectToWiFi();

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  delay(1000);
}

void connectToWiFi() {
  status_t wifiStatus = STATUS_DISCONNECTED;

  while (wifiStatus != STATUS_CONNECTED) {

    if (cc3k.begin()) {
      if (cc3k.connectToAP(WIFI_SSID, WPA_PASSWORD, WLAN_SEC_WPA2)) {
        wifiStatus = cc3k.getStatus();
      }
    }
    
    delay(5000);
  }

  cc3k.checkDHCP();
}

void loop() {
  TembooChoreo GetWeatherByAddressChoreo(client);

  GetWeatherByAddressChoreo.begin();

  GetWeatherByAddressChoreo.setAccountName(TEMBOO_ACCOUNT);
  GetWeatherByAddressChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
  GetWeatherByAddressChoreo.setAppKey(TEMBOO_APP_KEY);

  String AddressValue = "1601 Maple Street Carrollton, GA 30116";
  GetWeatherByAddressChoreo.addInput("Address", AddressValue);

  GetWeatherByAddressChoreo.setChoreo("/Library/Yahoo/Weather/GetWeatherByAddress");

  GetWeatherByAddressChoreo.addOutputFilter("temperature", "/rss/channel/item/yweather:condition/@temp", "Response");

  GetWeatherByAddressChoreo.run();

  while(GetWeatherByAddressChoreo.available()) {

    int temp = GetWeatherByAddressChoreo.read();

    if (temp < 55) {
      analogWrite(BLUE, 255 - 255);
      analogWrite(RED, 255 - 0);
      analogWrite(GREEN, 255 - 0);
    } 
    else if (temp <= 70 && temp > 55) {
      analogWrite(BLUE,255 - 0);
      analogWrite(RED,255 - 255);
      analogWrite(GREEN,255 - 255);
    } 
    else if (temp > 70) {
      analogWrite(BLUE,255 - 0);
      analogWrite(RED,255 - 255);
      analogWrite(GREEN,255 - 0);
    } 


  }
  GetWeatherByAddressChoreo.close();

  delay(5000);
}













