#include <SPI.h>
#include <WiFi.h> //wifi library
 
char ssid[] = "RKD_4G"; //  wifi network SSID (name)
char pass[] = "nishara94";    // wifi network password
 
int status = WL_IDLE_STATUS;
// numeric IP of your local machine
char server[] = "192.168.8.102";  
 
// Initialize the Wifi client library
WiFiClient client;
 
 int j1R1,j2R1,j3R1;
 int j1R2,j2R2,j3R2;
 int j1R3,j2R3,j3R3;
 int j1R4,j2R4,j3R4;
 
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
    while ( status != WL_CONNECTED) {
      Serial.print("Attempting to connect to SSID: ");
      Serial.println(ssid);
      status = WiFi.begin(ssid, pass);
      //status = WiFi.begin(ssid,pass);
      delay(10000);  // wait 10 seconds for connection to establish:
    }
    Serial.println("Connected to wifi");
    printWifiStatus();
}
 
 
// helper function that prints various wifi connection parameters to serial port
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
 
 
void loop()
{
    Road1();
    Road2();
    //Road3();
    SendData("junction1");
   // SendData("junction2");
}



void SendData(String junction){
  

// connect to the server
    if (client.connect(server, 80))
    {
        // print to serial monitor
        Serial.println("connected...");
        Serial.println("ARDUINO: forming HTTP request message");
 
        //send data the server through GET request
        client.print("GET /traffic/insert.php?&jname=");
        client.print(junction);
        
        client.print("&rname=");
        client.print("'R1'");
        client.print("&count1=");
        client.print(j1R1);

        client.print("&rname=");
        client.print("'R2'");
        client.print("&count2=");
        client.print(j1R2);

        client.print("&rname=");
        client.print("'R3'");
        client.print("&count3=");
        client.print(j1R3);

        client.print("&rname=");
        client.print("'R4'");
        client.print("&count4=");
        client.print(j1R4);
        
        //client.print("GET /traffic/insert.php?&jname='J1'&rname='R3'&count=");
        //client.print(31);
        client.println(" HTTP/1.1");
        client.print("HOST: ");
        client.println(server);
        client.println();
 
        Serial.println("ARDUINO: HTTP message sent");        
 
        // give server some time to receive and store data
        // before asking for response from it
        delay(3000);
 
        // get the response from the page and print it to serial port
        // to ascertain that data was received properly
        if(client.available())
        {
            Serial.println("ARDUINO: HTTP message received");
            Serial.println("ARDUINO: printing received headers and script response...\n");
 
            while(client.available())
            {
                char c = client.read();
                Serial.print(c);
            }
        }
        else
        {
            Serial.println("ARDUINO: no response received / no response received in time");
        }
 
        client.stop();
    }
    // do nothing forever after:
        delay(5000);
  
  
  
}



void Road1(){

     j1R1 = random(0,100);
     j1R2 = random(0,100);
     j1R3 = random(0,100);
     j1R4 = random(0,100);  
  }

void Road2(){

     j2R1 = random(0,100);
     j2R2 = random(0,100);
     j2R3 = random(0,100);
     j2R4 = random(0,100);  
  }

  void Road3(){

     j2R1 = random(0,100);
     j2R2 = random(0,100);
     j2R3 = random(0,100);
     j2R4 = random(0,100);  
  }

