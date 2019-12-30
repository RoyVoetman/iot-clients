#include <Arduino.h>
#include <ESP8266WiFi.h>

const char *ssid = "";  //Enter your wifi SSID
const char *password = "";  //Enter your wifi Password

int port = 8888;  //Port number
IPAddress ip;
WiFiServer server(port);

int sensorPin = A0;
void setup()
{
    Serial.begin(9600);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password); //Connect to wifi
  
    // Wait for connection  
    Serial.println("Connecting to Wifi");
    while (WiFi.status() != WL_CONNECTED) {   
        delay(500);
        Serial.print(".");
        delay(500);
    }

    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);

    Serial.print("IP address: ");
    ip = WiFi.localIP();
    Serial.println(ip);

    server.begin();
    Serial.print("Open Telnet and connect to IP:");
    Serial.print(ip);
    Serial.print(" on port ");
    Serial.println(port);
}
 
void loop()           
{
    WiFiClient client = server.available();
      
    if (client) {
        if(client.connected()) {
            Serial.println("Client Connected");
        }
        
        while(client.connected()) {   
            int reading = analogRead(sensorPin);

            char str[6];
            sprintf(str, "%d\n", reading);

            client.write(str);
            Serial.println(reading);
            delay(1000);  
        }
      
        client.stop();
        Serial.println("Client disconnected");    
    }                            
}