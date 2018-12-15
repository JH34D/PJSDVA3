

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
#include <ArduinoJson.h> //json https://github.com/bblanchon/ArduinoJson, installed using the arduino library manager.

//bronnen: Voorbeeldcode BB, https://techtutorialsx.com/2018/06/02/esp8266-arduino-socket-server/

#define I2C_SCL    D1
#define I2C_SDA    D2


//Wifi gegevens
char ssid[] = "Korsakov";
char pass[] = "P@ssw0rd";

WiFiServer wifiServerWemos(3333); //create object of wifiserver which will listen on the specified port
char receivedData[4096]; //create array to store received data
uint16_t rdIndex = 0; //index for receivedData array
char sensors[] = "{\"sittingDown\":0}";
char actions[] = "{\"vibrate\":0}";

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(115200);
  setIOConfig(15); //select I/O mode
  //set static ip outside dhcp scope
  IPAddress ip(192, 168, 3, 10);
  IPAddress gateway(192, 168, 3, 90);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.config(ip, gateway, subnet);
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
  setIOOutput(0); //start with all outputs 0

}

void loop() {
  /*
     Chair

    I/O Description Mfr. No:  Mfr.
    DI 0  Push Button
    DI 1
    DI 2
    DI 3
    DO 4  LED
    DO 5  Vibration Motor
    DO 6
    DO 7
    AI 0  Force Sensor  SEN-09375 Sparkfun
    AI 1


    functionele werking stoel:
    trillen (bijv na 10 uur. aansturing via Pi)
    lezen druksensor (melding als in stoel)
  */


  //client handling
  WiFiClient client = wifiServerWemos.available(); //check for and accept connections

  if (client) { //if connection has been acceted
    //print data of connected client
    IPAddress clientIP = client.remoteIP(); //store client IP
    uint16_t clientPort = client.localPort();
    Serial.print("Client connected with ip ");
    Serial.print(clientIP);
    Serial.print(" on port ");
    Serial.println(clientPort);

    while (client.connected()) { //while client connected

      if (receivedData[0] != '\0') { //data has been placed in array because the first char isnt the end of the string
        receivedData[rdIndex] = '\0'; //Add terminate string indicator at end of chars
        Serial.println(receivedData);

        if (receivedData[0] == 'i') { //indicates request for input

          StaticJsonBuffer<200> jsonBuffer2;
          JsonObject& sensorsJson = jsonBuffer2.createObject();
          if (readAdc() > 700) {
            sensorsJson.set("sits", 1);
          }
          else {
            sensorsJson.set("sits", 0);
          }
          String response;
          sensorsJson.printTo(response);
          client.print(response);
        }
        else if (receivedData[0] == 'o') { //indicates request for output
          char* request = receivedData + 2; //stip request indicator and space
          Serial.println("request is: " + (String) request);
          StaticJsonBuffer<200> jsonBuffer1;
          JsonObject& outputsJson = jsonBuffer1.parseObject(request);
          bool vibrate = outputsJson["vibrate"]; //variable = value of key chair in json
          if (vibrate) {
            setIOOutput(2);
          }
          else {
            setIOOutput(0);
          }
        }

        rdIndex = 0; //reset index
        receivedData[0] = '\0'; //set start of string as end of string
      }
      while (client.available() > 0) { //while data from client availabel

        char c = client.read(); //read char
        receivedData[rdIndex++] = c; //add char to "string"

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
}

unsigned int readIO() {
  Wire.beginTransmission(0x38);
  Wire.write(byte(0x00));
  Wire.endTransmission();
  Wire.requestFrom(0x38, 1);
  unsigned int input = Wire.read();
  return input & 0x0F;
}

unsigned int readAdc() {
  Wire.requestFrom(0x36, 4);
  unsigned int anin0 = Wire.read() & 0x03;
  anin0 = anin0 << 8;
  anin0 = anin0 | Wire.read();
  unsigned int anin1 = Wire.read() & 0x03;
  anin1 = anin1 << 8;
  anin1 = anin1 | Wire.read();

  return anin0;
}




