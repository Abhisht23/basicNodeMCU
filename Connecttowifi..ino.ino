#include<ESP8266WiFi.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("OPPO A9","Abhisht@2302");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.println("..");
    delay(200);
  }
  Serial.println();
  Serial.println("Board is connected");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
