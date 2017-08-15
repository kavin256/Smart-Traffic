#include <SoftwareSerial.h>
#include <SPI.h>
#include <WiFi.h> //wifi library
#include <Wire.h>
#include <SoftwareSerial.h>

int count = 0;
const int trigPin = 2;
const int echoPin = 4;


char ssid[] = "RKD_4G"; //  wifi network SSID (name)
char pass[] = "nishara94";    // wifi network password
 String a;
int status = WL_IDLE_STATUS;

char server[] = "192.168.8.100";  
 
// Initialize the Wifi client library
WiFiClient client;

long duration, inches, cm;


void setup()
{

  

    Serial.begin(9600);
 
    // check for the presence of the shield:
    if (WiFi.status() == WL_NO_SHIELD) {
      Serial.println("WiFi shield not present");
      // don't continue:
      while(true);
    }
 
    // attempt to connect to Wifi network:
    // will keep on trying every 10 seconds until connected
    //while ( status != WL_CONNECTED) {
      Serial.print("Attempting to connect to SSID: ");
      Serial.println(ssid);
      status = WiFi.begin(ssid, pass);
      //status = WiFi.begin(ssid,pass);
      delay(10000);  // wait 10 seconds for connection to establish:
   // }
    Serial.println("Connected to wifi");
    printWifiStatus();

  
}

void loop()
{
Read();
}


void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
 
  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
 
  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}


/////////////////////////////////


void Read(){
  
  int duration, inches, cm;

  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.println(cm);
 
  
  delay(100);  

  
}



long microsecondsToInches(long microseconds)
{
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}


