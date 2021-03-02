#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);

#define led D5
int value= LOW; 
void setup() 
{
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
  server.begin();
  pinMode(led, OUTPUT);
  digitalWrite (led,LOW);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  client = server.available();  //Gets a client that is connected to the server and has data available for reading.    
  if (client == 1)
  {  
    String request =  client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if(request == "GET /ledon HTTP/1.1")
    {
      digitalWrite(led, HIGH);
    }
    if(request == "GET /ledoff HTTP/1.1")
    {
      digitalWrite(led, LOW);
    }
  }
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("Led pin is now: ");
 
  if(value == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/ledon\"\"><button>Turn On </button></a>");  
  client.println("<a href=\"/ledoff\"\"><button>Turn Off </button></a><br>");  
  client.println("</html>");
 
  delay(1);
 // Serial.println("Client disonnected");
  //Serial.println("");
 
}
