#pragma once
//Activation Year is the current year or before 
class exc_act
{

public:
	const char* what() const throw() {
		return "Year cannot be > 2021 !\n";
		}
	exc_act();
	~exc_act();
};

