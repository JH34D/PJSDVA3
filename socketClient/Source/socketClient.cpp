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
#include "json.hpp" //json

#include "File.h" //class for filehandling
#include "devices/Chair.h"	//class for device chair
#include "sockClient.h" // class with socket functions


using namespace std;
using namespace nlohmann;

int main(int argc, char** argv)
{

sockClient client; //create object
if(argc == 3) //if enough arguments are passed, use arguments to set ip and port
{
	client = sockClient((string)argv[1], atoi(argv[2]));
}
else //if not, use default ip and port
{
	client = sockClient("192.168.3.10", 3333);
}
const char* ip = "192.168.3.10";
const char* path = "/home/pi/workingDir/output.json";
Chair chair1 = Chair(ip, 3333, path);

while(1){
chair1.handleActions();

//TODO read PHP, decide actions for device, set data for  this device, handle device

}
//cin.get();
return 0;
}

