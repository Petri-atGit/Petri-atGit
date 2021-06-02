#include "Cntrl.h"
#include <iostream>
#include <fstream>
#include "exc_act.h"
#include "exc_retire.h"

Cntrl::Cntrl()
//Info: controller constructor
// In: 
//Out:
{
	
}


Cntrl::~Cntrl()
//Info: controller Destructor
// In: 
//Out:
{
}

std::vector<Vehicle*> Cntrl::getAll()
//Info: returns all elements from the container
// In: 
//Out:
{
	return  this->repo.getData();
}



void Cntrl::addAqVehicle(string serial_number, string model, bool operational_status, int activation_year, int retire_by,string course)
//Info: Adding a aquatic vehicle 
// In: Parameters
//Out:
{
	AquaticVehicle* newVehicle = new AquaticVehicle();
	if (activation_year > 2021)
		throw exc_act();
	if (retire_by < activation_year)
		throw exc_retire();

	newVehicle->setSerialNr(serial_number);
	newVehicle->setModel(model);
	newVehicle->setOp_Status(operational_status);
	newVehicle->setActivation(activation_year);
	newVehicle->setDeactivation(retire_by);
	newVehicle->setcourse(course);

	this->repo.add(newVehicle,0);
}


void Cntrl::addAVehicle(string serial_number, string model, bool operational_status, int activation_year, int retire_by, string route)
//Info: Adding a Aerian vehicle 
// In: Parameters
//Out:
{
	AerianVehicle* newVehicle = new AerianVehicle();
	if (activation_year > 2021)
		throw exc_act();
	if (retire_by < activation_year)
		throw exc_retire();
	newVehicle->setSerialNr(serial_number);
	newVehicle->setModel(model);
	newVehicle->setOp_Status(operational_status);
	newVehicle->setActivation(activation_year);
	newVehicle->setDeactivation(retire_by);
	newVehicle->setRoute(route);
	this->repo.add(newVehicle, 0);

}


void Cntrl::addTVehicle(string serial_number, string model, bool operational_status, int activation_year, int retire_by,string road)
//Info: Adding a terrestrial vehicle 
// In: Parameters
//Out:
{
	TerrestrialVehicle* newVehicle = new TerrestrialVehicle();
	if (activation_year > 2021)
		throw exc_act();
	if (retire_by < activation_year)
		throw exc_retire();
	newVehicle->setSerialNr(serial_number);
	newVehicle->setModel(model);
	newVehicle->setOp_Status(operational_status);
	newVehicle->setActivation(activation_year);
	newVehicle->setDeactivation(retire_by);
	newVehicle->setroad(road);
	this->repo.add(newVehicle, 0);

}




void Cntrl::addVehicle(string serial_number, string model, bool operational_status, int activation_year, int retire_by)
//Info: Adding a baisc vehicle 
// In: Parameters
//Out:
{
	Vehicle* newVehicle = new Vehicle();
	if (activation_year > 2021)
		throw exc_act();
	if (retire_by < activation_year)
		throw exc_retire();
	newVehicle->setSerialNr(serial_number);
	newVehicle->setModel(model);
	newVehicle->setOp_Status(operational_status);
	newVehicle->setActivation(activation_year);
	newVehicle->setDeactivation(retire_by);

	this->repo.add(newVehicle,0);
}


void Cntrl::SortByDeactivation(int year)
{
	/*
	* Description: prints a list of vehicles by a given year
	* Parameters: int year(<2021)
	*/
	this->repo.SortByDeactivation(year);
}

void Cntrl::SortByModel(string model)
{
	/*
	* Description: prints a list of vehicles by a given brand
	* Parameters: string brand
	*/
	this->repo.SortByModel(model);
}






void Cntrl::STF()
{
	//Info: Saves vehicles to database
	// 
	//
	vector<Vehicle*> allVehicles = this->repo.getData();

	string fileName = "DB.txt";
	ofstream out(fileName);

	for (Vehicle* veh : allVehicles) {
		string stringVehicle = veh->toString();
		out << stringVehicle<<"\n";

	}cout << "Saved! " << endl;
}

void Cntrl::AFF()
{
	// Info: adds some vehicles from database
	//
	//
	string fileName = "DB.txt";
	ifstream in(fileName);
	std::string s;
	string serial_number, model;
	bool operational_status;
	int  activation_year, retire_by;
	while (!in.eof())
	{
		while (!in == '\0') {
			in >> serial_number;in >> model;in >> operational_status;in >> activation_year;in >> retire_by;
		}
		Vehicle* veh = new Vehicle(serial_number, model, operational_status, activation_year, retire_by);
		repo.add(veh, 0);
	}
}



void Cntrl::editBySnr(string serial_number, string model, bool operational_status, int activation_year, int retire_by)
//Info: edit an element from repo by snr
//In: parameters to be edited
//Out:
{
	this->repo.editBySNr(serial_number,  model, operational_status, activation_year, retire_by);
}




void Cntrl::removeBySNr(string snr)
//Info: removes an element from repo by snr
//In: Snr 
//Out:
{
	this->repo.removeBySNr(snr,0);
}



void Cntrl::undo()
{
	//Info: undo the last operation
	// 
	//
	this->repo.undo();
}




void Cntrl::redo()
{
	//Info: redo for the last operation
	// 
	//
	this->repo.redo();
}