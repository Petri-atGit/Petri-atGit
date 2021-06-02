#pragma once
class exc_retire
{
	//exception in case retiring year is smaller than activation year
	//Activation Year is before retire year
public:
	const char* what1() const throw() {
		return "Year cannot be < activation year !\n";
	}
	exc_retire();
	~exc_retire();
};




