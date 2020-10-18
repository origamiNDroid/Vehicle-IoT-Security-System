#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "HomeWiFiCredentials.h"
#define TAMPERTHRESHOLD 10
const int buzzer = 4; //buzzer to arduino pin 9
ESP8266WebServer server(80);

int prevValue = 0;
int currValue = 0;
bool counter = false;

void handleSentVar() {
  if (server.hasArg("sensor_reading")) { // this is the variable sent from the client
    int readingInt = server.arg("sensor_reading").toInt();
    server.send(200, "text/html", "Data received");
    currValue = readingInt;
    Serial.println(readingInt);
    int difference = abs(prevValue - currValue);
    Serial.print("difference\t");
    Serial.println(difference);
    if((abs(prevValue - currValue)> TAMPERTHRESHOLD)&& (counter == true)){
      tone(buzzer, 500); // Send 500 Hz Sound
      Serial.println("buzzer");
    }
    
    counter = true;
    prevValue = currValue;
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();

  server.on("/data/", HTTP_GET, handleSentVar); // when the server receives a request with /data/ in the string then run the handleSentVar function
  server.begin();

  pinMode(buzzer, OUTPUT);
}

void loop() {
  server.handleClient();
   //Serial.println("loop");
}
