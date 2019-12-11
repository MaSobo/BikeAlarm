# BikeAlarm
An Arduino based bike alarm using Bluetooth app to arm/disarm the alarm

This project uses:
-Arduino Uno / Nano
-HC-05 Bluetooth module
-Piezo buzzer
-SW-520D ball switch
-4 x 1 kOhm resistors

-breadboard
-jumper cables

- Arduino Bluetooth APP avaliable from Google Play

  The premise is rather simple - when armed, the Arduino is following the analog signal read from the ball switch, which in return is detecting and tils, vibrations, etc happening to the bike [or in this test case the breadboard]. The signal is substracted from the value of the signal when the sensor is at rest and if the difference breaches the set treshold, the buzzer will emit an annoying bi-tonal sound which length can be set. 

  Couple of notes regarding the HC-05 module:
  - 
