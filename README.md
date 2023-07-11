# Accident-Prevention-in-Hilly-Areas-using-WSN-with-ESPNOW
This project proposes using wireless sensor networks and ESPNOW protocol to improve accident avoidance in hilly areas by notifying drivers of approaching vehicles on the opposite side of the slope.

It uses 
- ESP8266 as Transmitter and Receiver
- IR sensors in TX sectoin
- OLED Display in RX section

Code
- CarPassDectection is used to detect the oneway vehicle passing detection algorithm.
- EspNowRX and EspNowTX are the main codes for both esp8266 modules.
- GetMac is used to get the MAC address required for the RX esp8266 module.
- IRcode is the code used for IR sensors.

Refer Methodology pdf for algoritm.
