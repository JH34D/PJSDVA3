#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "sockClient.h"
#include <stdlib.h> //atoi

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
///*
int main(int argc, char** argv)
{


	//create object
	sockClient client;
	///*
	if(argc == 3) //if enough arguments are passed, use arguments to set ip and port
	{
		client = sockClient((string)argv[1], atoi(argv[2]));
	}
	else //if not, use default ip and port
	{
		client = sockClient("192.168.3.228", 3333);
	}//*/
	 //create socket
	client.createSock(&client);
	client.setHint(&client);

	client.connectToServer(client.server, &client);


	while(1){
		//send
		cout << ">" ; //indicate send mode.
		string data; //
		getline(cin, data); //get data getline to prevent sending till return is pressed
		/*if data == " quit" do break*/
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
	client.closeSocket(&client);
	return 0;
}
//*/

