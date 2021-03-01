#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "3yxBcm-o8tMa1aMOTy_PA0b1xoF3yVwd";
char ssid[] = "OPPO A9";
char pass[] = "Abbhisht@2302";

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, "OPPO A9", "Abhisht@2302");
}

void loop()
{
  Blynk.run();
}
