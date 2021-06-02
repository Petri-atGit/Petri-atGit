#include "AerianVehicle.h"

AerianVehicle::AerianVehicle()
{
	this->route = "base";
}

AerianVehicle::AerianVehicle(string serial_number, string model, bool operational_status, int activation_year, int retire_by, std::string route)
{	
	this->serial_number = serial_number;
	this->model = model;
	this->operational_status = operational_status;
	this->activation_year = activation_year;
	this->retire_by = retire_by;
	this->route = route;
}

AerianVehicle::~AerianVehicle()
{
}

string AerianVehicle::getRoute()
{
	return this->route;
}



void AerianVehicle::setRoute(string route)
{
	this->route = route;
}

std::string AerianVehicle::toString()
{
	return Vehicle::toString() + "  " + this->route + "\n";
}
