#pragma once
// Exception for the ui menu.
class exc_opt_input
{
public:
	const char* wut() const throw() {
		return "Invalid input !\n";
	}
	exc_opt_input();
	~exc_opt_input();
};

