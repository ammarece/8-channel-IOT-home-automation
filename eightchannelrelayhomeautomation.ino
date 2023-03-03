/*
Code Name: Eight Channel Relay Home Automation
Author: AMMARECE
Description: This program used for Eight Channel Relay IOT Home Automation with the help of Blynk IoT.
License: Remixing or Changing this Thing is allowed. Commercial use is not allowed.
*/
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "YourAuthToken";
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

#define RELAY_1 D5 // GPIO14 for relay 1
#define RELAY_2 D6 // GPIO12 for relay 2
#define RELAY_3 D7 // GPIO13 for relay 3
#define RELAY_4 D8 // GPIO15 for relay 4
#define RELAY_5 D1 // GPIO5 for relay 5
#define RELAY_6 D2 // GPIO4 for relay 6
#define RELAY_7 D3 // GPIO0 for relay 7
#define RELAY_8 D4 // GPIO2 for relay 8

BlynkTimer timer;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);
  pinMode(RELAY_5, OUTPUT);
  pinMode(RELAY_6, OUTPUT);
  pinMode(RELAY_7, OUTPUT);
  pinMode(RELAY_8, OUTPUT);

  timer.setInterval(1000L, checkRelayStatus); // check relay status every 1s
}

void loop()
{
  Blynk.run();
  timer.run();
}

void checkRelayStatus()
{
  Blynk.virtualWrite(V1, digitalRead(RELAY_1));
  Blynk.virtualWrite(V2, digitalRead(RELAY_2));
  Blynk.virtualWrite(V3, digitalRead(RELAY_3));
  Blynk.virtualWrite(V4, digitalRead(RELAY_4));
  Blynk.virtualWrite(V5, digitalRead(RELAY_5));
  Blynk.virtualWrite(V6, digitalRead(RELAY_6));
  Blynk.virtualWrite(V7, digitalRead(RELAY_7));
  Blynk.virtualWrite(V8, digitalRead(RELAY_8));
}

BLYNK_WRITE(V1)
{
  digitalWrite(RELAY_1, param.asInt());
}

BLYNK_WRITE(V2)
{
  digitalWrite(RELAY_2, param.asInt());
}

BLYNK_WRITE(V3)
{
  digitalWrite(RELAY_3, param.asInt());
}

BLYNK_WRITE(V4)
{
  digitalWrite(RELAY_4, param.asInt());
}

BLYNK_WRITE(V5)
{
  digitalWrite(RELAY_5, param.asInt());
}

BLYNK_WRITE(V6)
{
  digitalWrite(RELAY_6, param.asInt());
}

BLYNK_WRITE(V7)
{
  digitalWrite(RELAY_7, param.asInt());
}

BLYNK_WRITE(V8)
{
  digitalWrite(RELAY_8, param.asInt());
}
