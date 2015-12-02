# Arduino Weather Lamp
Arduino Lamp which changes color depending on the weather outside. Uses Temboo web service to receive XML response with current weather information for a particular location. 
Parse the information and depending on the weather the color will change (cold - dark blue, warm - orange, hot - red).

# Hardware:

Arduino Uno $20

Powered by 9V DC adapter $5

CC3000 LinkSprite WiFi Shield ~$20

Solderless Breadboard ~$2

Jumper Wires ~$4

RGB LED ~$3

Acrylic Sheet Cube (sanded down to be frosted) aka Plexiglass ~$10

Total: ~$60 

# Software:

To run and successfully connect to a wireless network, you must install Arduino IDE 1.0.x (https://www.arduino.cc/en/Main/OldSoftwareReleases) as the updated IDE does not bode well with the older LinkSprite WiFi Shield. 
Also, you must import the Arduino CC library (included in this repository). 

To run Temboo, you must import the library (included in this repository). I have a signed up for the free service and my credentials are located in the TembooAccount.h header file. You
have a limited number of "free" API requests and you can log in my account to view the number of requests remaining. 

Step-by-step guide: 

https://imgur.com/a/VHiup





