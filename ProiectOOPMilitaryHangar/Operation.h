#pragma once
#include "Vehicle.h"

enum OperationType {
	add, rem, modify
};
class Operation
{

	OperationType operationType;
	Vehicle* vehicle;
public:
	Operation();
	Operation(Vehicle* veh, OperationType type);
	~Operation();
	OperationType getOperation();
	Vehicle* getVehicle();
};

