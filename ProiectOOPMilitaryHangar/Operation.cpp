#include "Operation.h"

Operation::Operation()
{
}

Operation::Operation(Vehicle* veh, OperationType type)
{
    this->vehicle = veh;
    this->operationType = type;
}

Operation::~Operation()
{
}

OperationType Operation::getOperation()
{
    return operationType;
}

Vehicle* Operation::getVehicle()
{
    return vehicle;
}
