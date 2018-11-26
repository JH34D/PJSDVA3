#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main() {

	string dataToWrite, wordsRead[10], stringRead;
	fstream dataFile;
	const char* path = "C:/forLinux/output.txt";
	


	dataFile.open(path); //open file


	if (dataFile.is_open()) { 
		getline(dataFile, stringRead);
		stringstream ss(stringRead);
		int index = 0;
		while (ss) {
			ss >> wordsRead[index++];
		}
	}
	else {
		cerr << "unable to open datafile..." << endl;
		return 88;
	}
	dataFile.close();

	if (wordsRead[0] == "w"){
		cout << "waiting" << endl;
		//sleep
	}
	else if (wordsRead[0] == "r") {
		
		if (wordsRead[1] == "led") {
			cout << "Leds zouden nu gezet zijn.....";
			//setleds()
			dataToWrite = wordsRead[2];
			
		}
	}
	

	

	//add if to execute only if data was read
	dataFile.open(path, ios::out); //open file
	if (dataFile.is_open()) {
		dataFile << dataToWrite;
	}
	else {
		cerr << "unable to open datafile..." << endl;
		return 88;
	}

	dataFile.close();

	cin.get();

}
