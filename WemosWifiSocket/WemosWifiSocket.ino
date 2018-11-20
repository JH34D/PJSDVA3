#include <ESP8266WiFi.h> //libs for wifi
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <Wire.h> //lib for i2c

//bronnen: Voorbeeldcode BB, https://techtutorialsx.com/2018/06/02/esp8266-arduino-socket-server/

#define I2C_SCL    D1
#define I2C_SDA    D2


//Wifi gegevens
char ssid[] = "Korsakov";
char pass[] = "P@ssw0rd";
WiFiServer wifiServerWemos(3333); //create object of wifiserver which will listen on the specified port
char receivedData[4096]; //create array to store received data
uint16_t rdIndex = 0; //index for receivedData array


void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(115200);
  setIOConfig(15); //select I/O mode
  // Connect to Wi-Fi network
  WiFi.mode(WIFI_STA); //set client mode
  WiFi.begin(ssid, pass); //begin connection (ssid and password)
  while (WiFi.status() != WL_CONNECTED) { //print a dot as long as the status isnt equal to connected.
    delay(500);
    Serial.print(".");
  }
  //passed the while so must be connected.
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); //print ip address for pinging purposes.

  //start wifiServer
  wifiServerWemos.begin();

  receivedData[0] = '\0';
}

void loop() {
  // put your main code here, to run repeatedly:
  // setIOOutput(15); //set leds
  //readIO(); //read switch state.
  // Serial.println(WiFi.localIP()); //print ip address for pinging purposes.

  //client handling
  WiFiClient client = wifiServerWemos.available();

  if (client) { //if client exists

    IPAddress clientIP = client.remoteIP(); //store client IP
    uint16_t clientPort = client.localPort();
    Serial.print("Client connected with ip ");
    Serial.print(clientIP);
    Serial.print(" on port ");
    Serial.println(clientPort);

    while (client.connected()) { //while client connected (might have to be moved to an interrupt)

      if (receivedData[0] != '\0') {
        receivedData[rdIndex] = '\0'; //Add terminate string indicator
        //switch met int waardes woorden of meerdere ifs met sting.equals(string2); mayb naar functie(string s) verplaatsen

        if (receivedData[1] == '\0') //if second char is end of line
        {
          if (receivedData[0] >= 48 && receivedData[0] <= 57)//case van maken voor meerder opties. werkt wel met [0] maar niet met string
          {
            setIOOutput(receivedData[0] - 48); //ascii to dec/hex
            client.print("OK");
          }
          else if (receivedData[0] >= 97 && receivedData[0] <= 102) {
            setIOOutput(receivedData[0] - 87); //ascii to hex
            client.print("OK");
          }
        }
        else if (strcmp(receivedData, "switches") == 0) { //if string matches
          client.print(readIO() & 0x0F);
        }
        else
        {
          client.print(receivedData); //Unknown command, echo to client
        }

        rdIndex = 0; //reset index
        receivedData[0] = '\0'; //set start of string as end of string

      }
      while (client.available() > 0) { //while data from client availabel

        char c = client.read();
        Serial.write(c); //write data to console
        receivedData[rdIndex++] = c;

      }

      delay(10); //small delay between data
    }
    //passed the while loop which means the client disconnected
    client.stop();
    Serial.println("Client disconnected");
  }
}



void setIOConfig(unsigned int input) { //add adress as parameter. define address
  Wire.beginTransmission(0x38);
  Wire.write(byte(0x03));
  Wire.write(byte(input/*0x0F*/));
  Wire.endTransmission();
}

void setIOOutput(unsigned int value) {
  Wire.beginTransmission(0x38);
  Wire.write(byte(0x01));
  Wire.write(byte(value << 4));
  Wire.endTransmission();
  Serial.print("Digital out: ");
  Serial.println(value);
}

unsigned int readIO() {
  Wire.beginTransmission(0x38);
  Wire.write(byte(0x00));
  Wire.endTransmission();
  Wire.requestFrom(0x38, 1);
  unsigned int input = Wire.read();
  Serial.print("Digital in: ");
  Serial.println(input & 0x0F);
  return input;
}



