#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 int PulseSensorPurplePin = 0;  	
int LED13 = 13; 
int Signal;        	
int Threshold = 300;
 String x;
String value ="A";
String value1 ="B";
 BlynkTimer timer;
char auth[] = "Co4fgYS3pKfuybyTC1VudJ77kc-el4SX";
char ssid[] = "LinasWifi";
char pass[] = "lina.anilk";
 void setup() {
  Serial.begin(9600);
  timer.setInterval(1000L, sendsensor);
  Blynk.begin(auth, ssid, pass);
}
void loop() {
  Serial.println("initializing");
  if (!Serial.available()){
	x = Serial.readString();
	Serial.println("Data from line:");
	Serial.println(x);
  }
if(x==value)
  {
	sendsensor();
   }
  else if(x==value1)
  {
	Serial.println("Status is Normal");
  }
  Blynk.run();
  timer.run();
}
void sendsensor()
{
  Signal = analogRead(PulseSensorPurplePin);
  Serial.println(Signal);
  delay(10);
  if(Signal > Threshold){                      	
 	Blynk.notify("ALERT");
 	Serial.println("AbNormal");
   } else {
 	Blynk.virtualWrite(V0,Signal);          	
   }
}
