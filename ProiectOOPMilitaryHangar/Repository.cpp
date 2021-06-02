#include "Repository.h"
#include <iostream>
#include <fstream>
#include"Operation.h"
#include<algorithm>

Repository::Repository()
//Info: Repo default constructor
//In: 
//Out: 

{
	this->array_size = 0;
}


Repository::~Repository()
//Info: Repo default destructor
//In: 
//Out: 


{

}

vector<Vehicle*> Repository::getData() const
//Info: Returns the container content
//In: 
//Out:  data

{
	return this->data;
}

int Repository::getLength()
{
	return this->array_size;
}


void Repository::add(Vehicle* newVehicle, int undo_id)
//Info: Repo adding function
//In: Vehicle pointer, undo_id
//Out: 

{
	this->data.push_back(newVehicle);
	this->array_size++;
	Operation* operation = new Operation(newVehicle, OperationType::add);
	if (undo_id != 1)
	{
		undo_stack.push(operation);
		if (undo_id == 0)
			while (!redo_stack.empty())
			{
				auto item = redo_stack.top();
				auto m = item->getVehicle();
				redo_stack.pop();
				delete item;
				delete m;

			}
		else
			redo_stack.push(operation);
	}
}



void Repository::removeBySNr(string snr, int undo_id)
//Info: Removes an elemenent from the container
//In:  snr for identification, undo_id
//Out: 

{
	for (auto it = this->data.begin(); it != this->data.end(); it++) 
	{
		if ((*it)->getSNr() == snr)
		{
			Vehicle* item = (*it);
			Operation* operation = new Operation(item, OperationType::rem);
			if (undo_id != 1)
			{
				undo_stack.push(operation);
				if (undo_id == 0)
				{
					while (!redo_stack.empty())
					{
						auto item = redo_stack.top();
						auto m = item->getVehicle();
						redo_stack.pop();
						delete item;
						delete m;
					}
				}
			}
			else
			{
				redo_stack.push(operation);
			}
			this->data.erase(it);
			break;
		}
	}
	this->array_size--;
}


void Repository::undo()
//Info: Undo's an operation
//In: 
//Out: 

{
	Operation* op = undo_stack.top();
	if (op->getOperation() == OperationType::add)
	{
		auto elem = op->getVehicle();
		removeBySNr(elem->getSNr(), 1);

	}
	else
		if (op->getOperation() == OperationType::rem)
		{
			auto elem = op->getVehicle();
			add(elem, 1);
		}
	undo_stack.pop();
}

void Repository::redo()
//Info: Redoes an operation that was undoed
//In: 
//Out: 

{
	
	Operation* operation = redo_stack.top();
	if (operation->getOperation() == OperationType::add)
	{
		auto elem = operation->getVehicle();
		removeBySNr(elem->getSNr(), 2);

	}
	else
		if (operation->getOperation() == OperationType::rem)
		{
			auto elem = operation->getVehicle();
			add(elem, 2);
		}
	redo_stack.pop();

}







void Repository::SortByDeactivation(int year)
{
	//info: sort all vehicle based on retiring year= year
	//IN: - year
	//OUT:
	vector<Vehicle*> v = this->getData();

	for_each(v.begin(), v.end(), [year](Vehicle* vehicle)
	{
		if ((*vehicle).getRetiringYear() == year)
			cout << *vehicle << endl;
	});
}

void Repository::SortByModel(string model)
{
	//info: sort all vehicle based on model= model
	//IN: - model
	//OUT:
	vector<Vehicle*> v = this->getData();

	for_each(v.begin(), v.end(), [model](Vehicle* vehicle)
	{
		if ((vehicle)->getModel() == model)
			cout << *vehicle << endl;
	});
}

void Repository::editBySNr(string serial_number, string model, bool operational_status, int activation_year, int retire_by)
{
	/*Description: changes the  Vehicle based on the given parameters
	* data in: string serial_number, string model, bool operational_status, int activation_year, int retire_by
	* data out:
	*/
	vector<Vehicle*> vec;
	for (auto it = this->data.begin(); it != this->data.end(); it++)
		if ((*it)->getSNr() == serial_number)
		{
			(*it)->setSerialNr(serial_number);
			(*it)->setModel(model);
			(*it)->setOp_Status(operational_status);
			(*it)->setActivation(activation_year);
			(*it)->setDeactivation(retire_by);

		}
}



