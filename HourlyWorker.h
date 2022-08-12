#ifndef _HOURLYWORKER_
#define _HOURLYWORKER_

#include <iostream>
#include <string>
#include "Employee.h"

class HourlyWorker : public Employee
{
public:

	/**
	Constructor: accepts a name, email, and hourly rate, setting the hours worked to 0 initially;

	@param name and email of the employee, the hourly pay rate
	*/
	HourlyWorker(std::string name, std::string email, int _rate, int _hours);

	/**
	Constructor: accepts an input file stream to read in the name, email, id,
	hours worked, and hourly rate;.

	@param the file name of the input string
	*/

	HourlyWorker(std::ifstream& inFile);

	/**
	This function that sets the hours worked;


	@param none
	@return type void, will modify the hours variable of the employe hours worked
	*/

	void set_hours();

	/**
	Override the print pay function here, define here to override the function for another definition of this class

	@param employee
	@return type void, prints out the employee's name and their pay amount
	*/

	void print_pay() const override
	{
		int amount = rate * hours;
		std::cout << Employee::get_name() << " receives $" << amount;
	}

	/**
	Override the save function to save the employee' function to the file

	@param employee
	@return type void, inputs information into the employee's file
	*/

	void save() override
	{
		Employee::write_data();
	}

	int get_rate();
	int get_hours();

private:
	int rate = 0; //  track the hourly pay rate
	int hours = 0; // track the integer number of hours worked

};
#endif