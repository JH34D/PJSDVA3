#include "Fridge.h"
#include <iostream>
#include "../sockClient.h"
#include "../File.h"

using namespace std;
using namespace nlohmann;

Fridge::Fridge(string ip, int port):Device(ip,port) {
	// TODO Auto-generated constructor stub

}

Fridge::~Fridge() {
	// TODO Auto-generated destructor stub
}

void Fridge::handleActions(){

	requestInputs();
	phpCom->updateData();
	handleFridge();
	handleTemp();
	setOutputs();
	phpCom->writeToFile();
}
void Fridge::handleFridge(){
	int fridgeSwitch = inputs.value("fridgeSwitch", 20); //get value if error return
				if (fridgeSwitch == 20){ //check for error
					cerr << "Error while reading input values. FridgeDoor could not be found in Json object in function handleBedtime() in class Fridge" << endl;
					fridgeSwitch = 0;
					//return;
				}
				if (fridgeSwitch == 14) {
					outputs["fridgeDoor"] = 1;
					phpCom->phpDataJson["fridge"] = 1;
				}
				else {
					outputs["fridgeDoor"] = 0;
					phpCom->phpDataJson["fridge"] = 0;
				}
}
void Fridge::handleTemp(){
	int tempSensor = inputs.value("tempSensor", 40);
	if (tempSensor == 40){ //check for error
						cerr << "Error while reading input values. TempSensor could not be found in Json object in function handleTemp() in class Fridge" << endl;
						tempSensor = 0;
						//return;
					}
					if (tempSensor > 8) {
						outputs["fridgeTemp"] = 1;//if the temperature above 8 set fridge on

					}
					else {

						outputs["fridgeTemp"] = 0;
					}

}


