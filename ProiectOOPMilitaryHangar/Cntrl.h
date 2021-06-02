#pragma once
#include "Repository.h"
class Cntrl
{
private:
	Repository repo;
public:
	Cntrl();
	~Cntrl();

	std::vector<Vehicle*> getAll();
	void addVehicle(string serial_number, string model, bool operational_status, int activation_year, int retire_by);
	void addTVehicle(string serial_number, string model, bool operational_status, int activation_year, int retire_by, string road);
	void addAqVehicle(string serial_number, string model, bool operational_status, int activation_year, int retire_by, string course);
	void addAVehicle(string serial_number, string model, bool operational_status, int activation_year, int retire_by, string route);
	void removeBySNr(string snr);
	void SortByDeactivation(int year);
	void SortByModel(string model);
	void STF();
	void AFF();
	void editBySnr(string serial_number, string model, bool operational_status, int activation_year, int retire_by);
	void undo();
	void redo();
};

