#include <iostream> //cout
#include <sys/types.h> //socket
#include <unistd.h> //socket
#include <sys/socket.h> //socket
#include <netdb.h> //socket
#include <arpa/inet.h> //socket
#include <string.h> //strings (legacy, needed for sockets)
#include <string> //strings
#include <stdlib.h> //atoi
#include <fstream> //read write files
//#include <sstream> //" cut"  strings
#include "json.hpp" //json https://github.com/nlohmann/json/tree/develop/single_include/nlohmann

#include "File.h" //class for filehandling
#include "sockClient.h" // class with socket functions
#include "devices/Chair.h"
#include "devices/Bed.h"
#include "devices/Column.h"
#include "devices/Door.h"
#include "devices/Fridge.h"
#include "devices/Window.h"

using namespace std;
using namespace nlohmann;

/*
 * TODO:
 * -add const keyword to function where no attributes are changed.
 * -add option for "Crosstalk"  between devices.
 * -Set receive Timeout to  a lower value
 * -update PHP in handle action function
 */


int main(int argc, char** argv)
{

//const char* ip = "192.168.3.10";
//const char* path = "/home/pi/workingDir/output.json"; //requires local file and permission for this file. (chmod 777 filename.json);


//Chair chair1 = Chair("192.168.3.10", 3333); // create object of type chair
//Bed bed1("192.168.3.11", 3333);
Column column1("192.168.3.12", 3333);
//Window window1("192.168.3.13", 3333);
//Door door1("192.168.3.14", 3333);
//Fridge fridge1("192.168.3.15", 3333);

while(1){

//chair1.handleActions();
//bed1.handleActions();
column1.handleActions();
//window1.handleActions();
//door1.handleActions();
//fridge1.handleActions();

//TODO read PHP, decide actions for device, set data for  this device, handle device. Currently done per device. might not be necessary to do in main.

}
//cin.get();
return 0;
}

