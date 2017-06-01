/*****************************************************************************
    This is an example for the ESP8266/CW01
    Demonstrates how to connect to WIFI Access Poinr

    You can buy these devices on our store!
     -----> https://xinabox.cc/CW01/

    This sketch connects specified WiFi Access Point

    Currently Supported on the following ☒CHIPs:
    - CW01

*****************************************************************************/

/************************** Library Includes ********************************/
#include <ESP8266WiFi.h>

/************************* WiFi Access Point *********************************/
// Replace the contents between inverted commas with your WiFi details.
// SSID is the name of the WIFI Hotspot.
// PASSWORD is the WIFI password.
const char* WIFI_SSID = "<YOUR_SSID>";
const char* WIFI_PASS = "<YOUR_VERY_SECRET_PASSWORD";

/**************************** SYSTEM DEFINES *********************************/
#define RED 12
#define GREEN 13
#define BLUE 5

/***************************** Sketch Code ***********************************/
void setup() {
  // Start the Serial Monitor
  Serial.begin(115200);
  
  // set pins as outputs
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  // Connect to WIFI
  WIFI_connect();
}

void loop() {
  // put your main code here, to run repeatedly:

}

// connect to WiFi network
void WIFI_connect() {
  if (WiFi.status() != WL_CONNECTED) {
    digitalWrite(GREEN, LOW);
    // Connect to WiFi access point.
    Serial.println(); Serial.println();
    Serial.print("Connecting to :");
    Serial.print("[");
    Serial.print(WIFI_SSID);
    Serial.print("]");

    // Start ESP8266 STA mode
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    // check connection status
    while (WiFi.status() != WL_CONNECTED) {
      digitalWrite(RED, HIGH);
      delay(100);
      digitalWrite(RED, LOW);
      delay(100);
      Serial.print(".");
    }
    if (WiFi.status() == WL_CONNECTED) {
      digitalWrite(GREEN, HIGH);
      Serial.println("[CONNECTED]");
    }
  }
}
