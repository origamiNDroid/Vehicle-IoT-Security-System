#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "ATTcs8D5kI";
const char *password = "3x5t4va+tyf5";

ESP8266WebServer server(80);

void handleSentVar() {
  if (server.hasArg("sensor_reading")) { // this is the variable sent from the client
    int readingInt = server.arg("sensor_reading").toInt();
    server.send(200, "text/html", "Data received");
    Serial.println(readingInt);
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();

  server.on("/data/", HTTP_GET, handleSentVar); // when the server receives a request with /data/ in the string then run the handleSentVar function
  server.begin();
}

void loop() {
  server.handleClient();
   //Serial.println("loop");
}
