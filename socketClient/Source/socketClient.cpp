#include <iostream> //cout
#include <sys/types.h> //socket
#include <unistd.h> //socket
#include <sys/socket.h> //socket
#include <netdb.h> //socket
#include <arpa/inet.h> //socket
#include <string.h> //strings (legacy, needed for sockets)
#include <string> //strings
#include "sockClient.h" // class with socket functions
#include <stdlib.h> //atoi
#include <fstream> //read write files
#include <sstream> //" cut"  strings
#include "File.h"



using namespace std;

/*to do:
 * create object
 * Create socket
 * create hint for server we re connecting to
 * connect to socket
 * read
 * write
 * close/destroy
 */

int main(int argc, char** argv)
{
const string outputPath = "/home/pi/workingDir/output.txt"; //move to class! (parameter)
fstream *outputFile = new fstream; //move to class?
File output = File(outputPath, outputFile);
sockClient client; //create object
if(argc == 3) //if enough arguments are passed, use arguments to set ip and port
{
	client = sockClient((string)argv[1], atoi(argv[2]));
}
else //if not, use default ip and port
{
	client = sockClient("192.168.3.228", 3333);
}
//create socket
client.createSock(&client); //todo create one for each device amd reove parameter (this.)
client.setHint(&client); //set connection for data
while(1){
	string dataRead = output.readFile();
		if(dataRead != "error"){
			string wordsRead[10];
			int index = 0;
			stringstream ss(dataRead);

			while (ss) {
			ss >> wordsRead[index++];
			}
		//possible commands, add check for amount read? for looop?
		if (wordsRead[0] == "led") //add check for<16 here or php?
		{
			//connect
			client.connectToServer(client.server, &client);

			if (!client.sendToServer(wordsRead[1])) //send data. if unable to send, stop
			{
					return 18;
			}
			if(client.receiveFromServer(&client) == "error") //wait for ack, if no ack give error
			{
					cerr << "Response timed out" << endl; //move to function?
					return 19;
			}
			//close socket
			//client.closeSocket(&client);
			output.writeToFile("OK");

		}
		else if (wordsRead[0] == "switches") {
			client.connectToServer(client.server, &client);
				if (!client.sendToServer(wordsRead[0])) //send data. if unable to send, stop
				{
						return 18;
				}
				sleep(1);//needed for determining whether or not the file changed (php)
				output.writeToFile(client.receiveFromServer(&client));
				//close socket
				//client.closeSocket(&client);
		}

	}

}
	return 0;
}

