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
#include <sstream> //" cut"  strings
#include "json.hpp" //json https://github.com/nlohmann/json/tree/develop/single_include/nlohmann

#include "File.h" //class for filehandling
#include "devices/Chair.h"	//class for device chair
#include "sockClient.h" // class with socket functions


using namespace std;
using namespace nlohmann;

int main(int argc, char** argv)
{

const char* ip = "192.168.3.10";
const char* path = "/home/pi/workingDir/output.json"; //requires local file and permission for this file. (chmod 777 filename.json);

Chair chair1 = Chair(ip, 3333); // create object of type chair
while(1){
chair1.handleActions();

//TODO read PHP, decide actions for device, set data for  this device, handle device

}
//cin.get();
return 0;
}

