/*p>The standard socket library in C comes with a lot of functions for every task like connecting, sending data and receiving data etc. However knowing the syntax of all the functions and calling them again and again and in the right sequence could be a bit intimidating. </p>
<p>Using a class can help in such a situation. It has fewer functions and a simpler syntax. The class however does call the actual socket functions from the library.</p>
<p>In this article we would try to code a wrapper class for "client" functionality. A socket client connects to a certain server on a certain port number and then sends some data and then waits for a reply. And it keeps doing this for as long as the application wishes to. Common examples of such clients are web browser and ftp clients. Web browsers connect to websites on port 80 and fetch the html content of the webpage and then render them on the screen for the user.</p>
<p>Before moving on, it is suggested that you get your concepts clear on the basic socket operations. This <a href="https://www.binarytides.com/beginners-guide-to-socket-programming-in-c-on-linux/">socket programming tutorial</a> can help.</p>
<h3>Code</h3>
<p>Now here we have coded a simple class called sockClient, which can be used to perform basic clientside socket operations like sending and receiving data from a tcp server on a certain port number.</p>
<p>The following code works only on linux.</p>
<pre class="brush: cpp; title: ; notranslate" title="">
	C++ client example using sockets
	*/
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "sockClient.h"

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
int main()
{
	//create object
	sockClient client = sockClient("192.168.3.228", 3333);


	client.createSock(&client);

	if(client.sock > 0)
	{
		cout << "Socket has been created: " << client.sock << endl;
	}
	client.setHint(&client);
	client.connectToServer(client.server, &client);
	while(1){
		//send
		cout << ">" ; //indicate send mode.
		string data; //
		getline(cin, data); //get data getline to prevent sending till return is pressed
		/*if data == " quit" do break*/
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

