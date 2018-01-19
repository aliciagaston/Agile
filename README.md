# Agile Week
Github repository for Dawin project during Agile week, this repository is for the server part of the project.
You'll find the client part there : https://gitlab.com/NicolasMarcilloux/LIDAR

* Google Drive : https://drive.google.com/drive/u/0/folders/10tHqHxTW0knj4FHQE4iXqZ4afd6rQHnd

## Get started
Install server on rasberry PI :
* Connect with rasberry using ssh.
* Copy server/ and src/ directory on pi
* run command ```make``` to compile
* run ```./server```

## Useful informations
### Rasberry

**SSH :**
* user : pi
* password : raspberry

**WIFI (AD-HOC)**
* SSID : raspi-wifi
* pwd : raspi123

### Arduino
* Port : /dev/ttyUSB0
* Speed : 115200 baud

**Commands :**
* Move Roll : MRxxx
* Move Yaw MYxxx
* GetCurrentPosition : G
* Go to Home : H

## Team
* Guillaume Nedelec
* Alicia Gaston
* Timothée Binet
* Pierre Dumoulin
* Gauthier Urso
* Arnaud Ayrem (RIP Buddy)
* Thomas Blanc