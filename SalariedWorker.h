#ifndef _SALARIEDWORKER_
#define _SALARIEDWORKER_

#include <iostream>
#include <string.h>
#include "Employee.h"

class SalariedWorker : public Employee
{
public:

	/**
	Constructor: accepts a name, email, and hourly rate, setting the hours worked to 0 initially;

	@param name and email of the employee, the hourly pay rate
	*/
	SalariedWorker(std::string name, std::string email, double salary);

	/**
	Constructor: accepts an input file stream to read in the name, email, id,
	hours worked, and hourly rate;.

	@param the file name of the input string
	*/

	SalariedWorker(std::ifstream& inFile);

	/**
	Override the print pay function here, define here to override the function for another definition of this class

	@param employee
	@return type void, prints out the employee's name and their salary amount
	*/

	void print_pay() const override
	{
		std::cout << Employee::get_name() << " receives $" << salary;
	}

	/**
	Override the save function to save the employee' function to the file

	@param employee
	@return type void, inputs information into the employee's txt file
	*/

	void save() override
	{
		Employee::write_data();
	}

private:
	double salary; // member variable salary for their salary

};
#endif




