#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3);// TX,RX

Servo s1,s2,s3;

String bt,bta,btb,btc;

int d1,d2,d3;

void setup() 
{
  s1.attach(5);
  s2.attach(6);
  s3.attach(7);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() 
{
  if(bluetooth.available())
  {
    bt=bluetooth.readString();  
    if(bt.indexOf("1#F") > -1)//servo 1
    {
      bta=bt.substring(3,bt.length());
      btb=bta.indexOf('>');
      btc=bta.substring(0,btb.toInt());
      Serial.println(btc);
      d1 = (btc.toInt());
      s1.write(d1);
    }
    if(bt.indexOf("2#F") > -1)//servo 2
    {
      bta=bt.substring(3,bt.length());
      btb=bta.indexOf('>');
      btc=bta.substring(0,btb.toInt());
      Serial.println(btc);
      d2 = (btc.toInt());
      s2.write(d2);
    }
    if(bt.indexOf("3#F") > -1)//servo 3
    {
      bta=bt.substring(3,bt.length());
      btb=bta.indexOf('>');
      btc=bta.substring(0,btb.toInt());
      Serial.println(btc);
      d3 = (btc.toInt());
      s3.write(d3);
    }
  }
}
