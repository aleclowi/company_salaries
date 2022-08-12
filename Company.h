#ifndef _COMPANY_
#define _COMPANY_

#include <iostream>
#include <string.h>
#include <vector>
#include <memory>
#include "Employee.h"

class Company
{
public:

	/**
	Constructor: reads through all the files and creates Employees
	of suitable type for each file, storing them as pointers;;

	@param name and email of the employee, the hourly pay rate
	*/
	Company(std::vector<std::shared_ptr<Employee>> employee);

	/**
	have a print directory function that displays how many employees are in the
	company and then runs through the vector and calls print on all entries;

	@param
	@return
	*/

	void print_directory();

	/**
	 have a do hours function that runs through the vector and through using a
	dynamic pointer cast, for the HourlyWorkers, prompts the user
	How many hours did [NAME] work?
	and following the user input, it should call set hours on the employee to set their
	hours and call save on the employee to save the changes;

	@param the file name of the input string
	@return
	*/

	void do_hours();

	/**
	 have a print payroll function that runs through the vector and calls the print pay
	function on all elements;

	@param
	@return
	*/

	void print_payroll();

	/**
	have a create salaried function that prompts a user for a name, email address,
	and salary for a SalariedWorker and instantiates that class, saves it, and adds it
	to employees - the dollar signs should be printed by the program, not entered by the user;

	@param
	@return
	*/

	void create_salaried();

	/**
	have a create hourly function that prompts a user for a name, email address, and
	hourly pay rate for an HourlyWorkerand instantiates that class, saves it, and
	adds it to employees - the dollar signs should be printed by the program, not
	entered by the user;

	@param
	@return
	*/

	void create_hourly();

	/**
	 have a create employee function that asks a user what type of employee they
	want to create with “S” for salaried, “H” for hourly worker; with other commands
	aborting the creation.

	@param
	@return
	*/

	void create_employee();

private:
	double salary; // member variable salary for their salary
	std::vector<std::shared_ptr<Employee>> employee;
};

/*find next id that serves as a helper function for setting the static member Employee::next id: it should read through all files “employee0.txt”, “employee1.txt”,
etc., until it fails to open a file at which point the integer index it failed at should
be returned and be the next id;
• run events that creates a company object and repeatedly prompts a user if they
would like to create/display/set/print as described previously, terminating when
they do not enter a “C”, “D”, “H”, or “P”.
*/
#endif




