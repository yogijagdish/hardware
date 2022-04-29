#include<ThingSpeak.h>
#include<SoftwareSerial.h>
#include<ESP8266WiFi.h>
SoftwareSerial nodemcu_communication(D1,D2);
WiFiClient client;
float datain;
long mychannel = 1713657;
const char apikey[] = "U29NSWTNGGQDE3QW";
void setup()
{
  Serial.begin(9600);
  nodemcu_communication.begin(9600);
  WiFi.begin("wrc7_fpkhr","p@ssw0rd");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("connecting ... ");
    delay(1000);
  }
  Serial.println("NodeMcu connected");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
  delay(500);
}
void loop()
{
 while (nodemcu_communication.available()>0)
 {
  datain = nodemcu_communication.read();
  Serial.println(datain);
  ThingSpeak.writeField(mychannel,1,datain,apikey);
  delay(5000);
 }
}
