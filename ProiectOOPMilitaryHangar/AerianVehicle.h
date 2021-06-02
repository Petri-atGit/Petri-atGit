#pragma once
#include "Vehicle.h"
class AerianVehicle : public Vehicle
{
private:
	std::string route;

public:
	AerianVehicle();
	AerianVehicle(string serial_number, string model, bool operational_status, int activation_year, int retire_by, std::string route);
	~AerianVehicle();
	string getRoute();
	void setRoute(std::string route);
	std::string toString();

};

