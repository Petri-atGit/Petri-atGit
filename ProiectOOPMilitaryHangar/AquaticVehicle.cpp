#include "AquaticVehicle.h"
AquaticVehicle::AquaticVehicle()
{
	this->course = "base";
}


AquaticVehicle::AquaticVehicle(string serial_number, string model, bool operational_status, int activation_year, int retire_by, std::string course)
{
	this->serial_number = serial_number;
	this->model = model;
	this->operational_status = operational_status;
	this->activation_year = activation_year;
	this->retire_by = retire_by;
	this->course = course;
}





AquaticVehicle::~AquaticVehicle()
{
}

string AquaticVehicle::getcourse()
{
	return this->course;
}



void AquaticVehicle::setcourse(string course)
{
	this->course = course;
}

std::string AquaticVehicle::toString()
{
	return Vehicle::toString() + "  " + this->course + "\n";
}
