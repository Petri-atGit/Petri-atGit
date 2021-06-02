#pragma once
#include "Vehicle.h"
class AquaticVehicle : public Vehicle
{
private:
	std::string course;

public:
	AquaticVehicle();
	AquaticVehicle(string serial_number, string model, bool operational_status, int activation_year, int retire_by, std::string coure);
	~AquaticVehicle();
	string getcourse();
	void setcourse(std::string course);
	std::string toString();

};

