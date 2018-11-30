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

#define OUTPUTFILE "/home/pi/workingDir/output.txt"
#define INUSEFILE "/home/pi/workingDir/inUse.txt"

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
//create object
sockClient client;
if(argc == 3) //if enough arguments are passed, use arguments to set ip and port
{
	client = sockClient((string)argv[1], atoi(argv[2]));
}
else //if not, use default ip and port
{
	client = sockClient("192.168.3.228", 3333);
}
//create socket
client.createSock(&client);
client.setHint(&client); //set connection for data

	string dataRead = output.readFile();
	if(dataRead != "error"){
		string wordsRead[10];
		int index = 0;
		stringstream ss(dataRead);
		while (ss) {
			ss >> wordsRead[index++];
		}
		//possible commands
		if (wordsRead[0] == "led") //add check for<16 (ascci)
		{
			//connect
			client.connectToServer(client.server, &client);

			cout << " tweede item is: " << wordsRead[1] << endl;

			if (!client.sendToServer(wordsRead[1])) //send data. if unable to send, stop
			{
					return 18;
			}
			if(client.receiveFromServer(&client) == "error") //wait for ack, if no ack give error
			{
					cerr << "Response timed out" << endl;
					return 19;
			}
			//close socket
			client.closeSocket(&client);

		}
		else {

		}

	}


	//add check to see if inusefile is there, if so wait till its not.







/*
	while(1){
		//send
		cout << ">" ; //indicate send mode.
		string data; //
		getline(cin, data); //get data getline to prevent sending till return is pressed

		if(data == "quit"){ //break from loop
			break;
		}
		if (!client.sendToServer(data)) //send data. if unable to send, break.
		{
			break;
		}

		//receive /respond
		if(client.receiveFromServer(&client) == "error")
		{
			cerr << "Response timed out" << endl;
			continue;
		}


	}
	*/


	return 0;
}

