#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "HomeWiFiCredentials.h"
#define TAMPERTHRESHOLD 10
const int buzzer = 4; //buzzer to arduino pin 9
const int BUTTON_PIN = 12; // D6-12 D0-16Arduino pin connected to button's pin
ESP8266WebServer server(80);

// variables will change:
int buzzerState = LOW;     // the current state of LED
int lastButtonState = HIGH;    // the previous state of button
int currentButtonState; // the current state of button

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
    if((difference > TAMPERTHRESHOLD)&& (counter == true)){
      tone(buzzer, 500); // Send 500 Hz Sound
      buzzerState = HIGH;
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
  
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  currentButtonState = digitalRead(BUTTON_PIN);
}

void loop() {
  server.handleClient();
   //Serial.println("loop");
   lastButtonState    = currentButtonState;      // save the last state
   currentButtonState = digitalRead(BUTTON_PIN); // read new state
if(buzzerState == HIGH){
  Serial.println("buzzer is High");
  Serial.print("lastButtonState is: \t");
  Serial.println(lastButtonState);
  Serial.print("currentButtonState is: \t");
  Serial.println(currentButtonState);
  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("The button is pressed");
    noTone(buzzer);
    currentButtonState = HIGH;
    buzzerState == LOW;
  }
}
}
