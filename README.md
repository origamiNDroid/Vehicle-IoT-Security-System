# Vehicle IoT Security System
An IoT security system for the theft prevention of vehicles.  This project was created at HackGT 2020 and was inspired by a rise in vehicle theft in my local community. I hope to make this a noninvasive product that is easy to reproduce and deploy. 
# Purpose 
Many vehicles are equipped with alarms. Unfortunately, the current alarm systems are not enough. Malicious events involving vehicles occur when the victim is away from the vehicle. Vehicles are often stolen at night and right from the victim's parking spot. Although many vehicles have alarm systems, it is difficult to hear alarms from inside a building, and criminals are aware of this. The solution I propose is to reimagine current alarms but within the realm of IoT or Internet of Things. By creating an IoT enabled device, the user is able to hear an alarm's sound from inside a building. Now with the Vehicle IoT Security System, users all over the globe will be prepared to safegaurd their vehicles.
# System Diagram
![](https://github.com/origamiNDroid/Vehicle-IoT-Security-System/blob/main/Vehicle%20IoT%20Security.jpg)
# HackGT 2020 Progress Summary
As of October 18, 2020 at 7:00am EST a functional demo and prototype of the vehicle device and the home device has been created.
# Vehicle Device
The vehicle device consists of an ESP8266 NodeMCU v1.0, a 9V battery, and an Adafruit LIS3DH Triple-Axis Accelerometer Breakout Board. This device is the client, and it connects to a nearby network of the user's choosing. This device is meant to be placed inside a vehicle. The device sends url formatted information regarding the vehicle's status, detected by the accelerometer, through the ESP8266 via a client-and-server protocol over a network connection. See the image below for the breadboard layout of the vehicle device.

![](https://github.com/origamiNDroid/Vehicle-IoT-Security-System/blob/main/bbpic_vehicledevice.JPG)
# Home Device
The home device consists of another ESP8266 NodeMCU v1.0, a push button, and a buzzer (I was expecting company so I went for the quieter route, but in reality I would use a speaker instead). If the data received by the home device from the vehicle device confirms tampering (theft, tow truck, vandalism, angry significant other, etc.), the alarm will sound via a speaker (or in this case buzzer). The alarm is disabled via push button until another tampering event occurs. The home device is powered through the NodeMCU's micro-usb type b port. See the image below for the breadboard layout of the home device.

![](https://github.com/origamiNDroid/Vehicle-IoT-Security-System/blob/main/bbpic_homedevice.JPG)
# Note
This project, although functional, is not ready for use. Development boards are not generally energy efficient. The vehicle device would not last longer than a few hours if used as is. This project is still under development. 
