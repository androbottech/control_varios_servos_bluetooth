#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3);// TX,RX

String bt,bta,btb,btc;

void setup() 
{
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() 
{
  if(bluetooth.available())
  {    
      bt=bluetooth.readString();
      if(bt.indexOf("1#F") > -1){
        bta=bt.substring(3,bt.length());
        btb=bta.indexOf('>');
        btc=bta.substring(0,btb.toInt());
        Serial.println(btc);
        //delay(10);
      }    
  }
}
