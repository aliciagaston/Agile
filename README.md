# Agile Week
## Get started


How to compile :


Compiling the demo's can be done as follows:

g++ main.cpp rs232.c -Wall -Wextra -o2 -o start_request


Run the demo by typing:

./start_request


To include this library into your project:

Put the two files rs232.h and rs232.c in your project/sourcedirectory.

Write #include "rs232.h" in your sourcefiles that needs access to the library.

Add the file rs232.c to your project settings (in order to get it compiled and linked with your program).


SSH ;
user : pi
pwd : raspberry

WIFI (AD-HOC)
SSID : raspi-wifi
pwd : raspi123

ARDUINO
Port : /dev/ttyUSB0
Speed 115200 baud
commandes :
Move Roll : MRxxx
Move Yaw MYxxx
GetCurrentPosition : G
Go to Home : H

double (entre  -90 et 90)