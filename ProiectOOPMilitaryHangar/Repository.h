#pragma once
#include "Vehicle.h"
#include "AquaticVehicle.h"
#include "AerianVehicle.h"
#include "TerrestrialVehicle.h"
#include <vector>
#include <stack>
#include "Operation.h"

class Repository
{
private:
	std::vector<Vehicle*> data;
	std::stack<Operation*> undo_stack;
	std::stack<Operation*> redo_stack;
public:
	int array_size;
	Repository();
	~Repository();

	std::vector<Vehicle*> getData() const;
	int getLength();
	void add(Vehicle* newVehicle, int undo_id);
	/*
	void addt(TerrestrialVehicle* newVehicle);
	void addaq(AquaticVehicle* newVehicle);
	void adda(AerianVehicle* newVehicle);
	*/
	void removeBySNr(string snr, int undo_id);
	void SortByDeactivation(int year);
	void SortByModel(string model);
	void editBySNr(string serial_number, string model, bool operational_status, int activation_year, int retire_by);
	void undo();
	void redo();
};

