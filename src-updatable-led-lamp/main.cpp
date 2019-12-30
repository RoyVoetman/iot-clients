#include <Arduino.h>
#include <NeoPixelBus.h>
#include <ESP8266WiFi.h>

#define colorSaturation 255

const char *ssid = "";  //Enter your wifi SSID
const char *password = "";  //Enter your wifi Password

const uint16_t PixelCount = 12; // aantal leds
const uint8_t PixelPin = 2;  // op de Esp8266 altijd de RX pin

int port = 8888;  //Port number
IPAddress ip;
WiFiServer server(port);

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> ring(PixelCount, PixelPin); // GRB!
HtmlColor htmlColor;

void setup()
{
    Serial.begin(9600);

    // Initialize the BUILTIN_LED pin as an output
    pinMode(LED_BUILTIN, OUTPUT); 
    ring.Begin();

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
            while(client.available()>0){
                String color = client.readStringUntil('\r');
                Serial.println(color);
                htmlColor.Parse<HtmlColorNames>(color);
                ring.ClearTo(htmlColor);
                ring.Show(); 
            }   
        }
        
        client.stop();
        Serial.println("Client disconnected");    
    }                            
}