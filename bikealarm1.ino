#include <SoftwareSerial.h>

#define buzzPin 3
#define tiltPin A0
#define ledPin LED_BUILTIN

SoftwareSerial BTserial(10, 11); // RX | TX - to have the ability of reading out the data in the serial monitor

int previousTilt = 1023;
int tilt;
int treshold = 50;
int alarmLength = 4;


char c=' ';

void setup() {
  Serial.begin(9600);
  BTserial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
 
}

bool bluetoothSwitchIsOn()
{
 if (BTserial.available())
  {
    c = BTserial.read();
    Serial.write(c);
    if(c == '1')
      { 
        return 1;
      }
    else
      {
        return 0;
      }
  }
}

bool checkForTheft()
{
  tilt=analogRead(tiltPin);
  
  if(previousTilt-tilt > treshold)
    {
      Serial.println(previousTilt-tilt);
      //previousTilt = tilt;
    
      return 1;
    }
  else 
    {
      return 0;
    }
}

void soundTheAlarm()
{
  for(int i=0; i<=alarmLength; ++i)
  {
    tone(buzzPin, 6000);
    delay(100);
    tone(buzzPin, 600);
    delay(100);
  }
  noTone(buzzPin);
}

void flashLED()
{
  digitalWrite(ledPin,HIGH);
  delay(100);
  digitalWrite(ledPin,LOW);
  delay(100);
}


void loop() {

if(bluetoothSwitchIsOn())
{
 flashLED();
 if(checkForTheft())
  {
   soundTheAlarm();
   
  }
}
else
{
  noTone(buzzPin);
  digitalWrite(ledPin, LOW);
}

}
