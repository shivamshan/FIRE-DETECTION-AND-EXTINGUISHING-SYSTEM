# FIRE-DETECTION-AND-EXTINGUISHING-SYSTEM
## Fire Detection Using Computer Vision On Raspberry Pi and Arduino.
This project aims at providing an alternative to the conventional fire alarms by using **image recognition** for fire detection instead of sensors.</br>
</n>
Using this new technique can result in faster detection of fire and hence lead to faster prevention.</br>

This project also shows how a **water supply system** can be integrated with the detecton system to extinguish the fire in its early stages itself.
</br>
</br>
This project makes use of **Raspberry Pi** Model 4b for the computer vision part and **Arduino Uno** for controlling the water system and also for warning the users.</br>
</br>
### In addition to the detection task, the Raspberry Pi also alarms the user by sending them an email with the picture of the detected fire. Therefore even if the user is outside the house, this system can warn him/her of the danger.
</br>

## FRONT VIEW OF THE DEVICE
<img src="https://github.com/shivamshan/FIRE-DETECTION-AND-EXTINGUISHING-SYSTEM/blob/master/front_view.jpg">

## INSIDE VIEW OF THE DEVICE
<img src="https://github.com/shivamshan/FIRE-DETECTION-AND-EXTINGUISHING-SYSTEM/blob/master/inside_view.jpg">

## CIRCUIT DIAGRAM OF THE DEVICE
### Connection to Arduino
<img src="https://github.com/shivamshan/FIRE-DETECTION-AND-EXTINGUISHING-SYSTEM/blob/master/connec2.png">

#### Note that the connection between Arduino and pump is not shown but it is present as can be seen in the above image with the help of a Single Channel Relay.

### Connection between Arduino and Raspberry Pi
The connection is between Arduino **analog pin A0** and Raspberry **GPIO pin 21.**
<img src="https://github.com/shivamshan/FIRE-DETECTION-AND-EXTINGUISHING-SYSTEM/blob/master/connec1.png">

## Alert email received
<img src="https://github.com/shivamshan/FIRE-DETECTION-AND-EXTINGUISHING-SYSTEM/blob/master/message.png">

## Image sent by Raspberry Pi on fire detection
<img src="https://github.com/shivamshan/FIRE-DETECTION-AND-EXTINGUISHING-SYSTEM/blob/master/pic.jpg">

# Click on the picture below to view demonstration video
<a href="https://drive.google.com/file/d/1ZKbGFgwxLcdaGvq_0TkWcMHmkZHxPGx0/view?usp=sharing"><img src="https://github.com/shivamshan/FIRE-DETECTION-AND-EXTINGUISHING-SYSTEM/blob/master/thumb.png"></a>
