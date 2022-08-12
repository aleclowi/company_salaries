#ifndef _EMPLOYEE_
#define _EMPLOYEE_

#include <iostream>
#include <string>

class Employee
{

public:

	/**
	Constructor: accepts the name of an employee and their email which creates an employee

	@param name and email of the employee
	*/
	Employee(std::string _name, std::string _email);

	/**
	Constructor: reads the file inputted and reads a name, email, and id from the stream#.

	@param the file name of the input string
	*/

	Employee(std::ifstream& inFile);

	virtual ~Employee() = default;
	Employee(Employee&&) noexcept = default;
	Employee(const Employee&) = default;
	Employee& operator=(Employee&&) noexcept = default;
	Employee& operator=(const Employee&) = default;

	/**
	This function that prints directory information of the form: [NAME] [TAB] [ID] [TAB] [EMAIL]
	to the console;


	@param none
	@return type void, will output employee directory information in the form of a string
	*/
	void print();

	/**
	This function (that could be overridden) that writes the name, email, and id of the Employee
	to a file, each entry separated by a tab

	@param employee
	@return type void, inputs information into a txt file
	*/

	void write_data();

	/**
	This virual function mandates functionality for printing payment information.

	@param none
	@return type void, prints pay
	*/

	virtual void print_pay() const
	{
		std::cout << name << "\t" << email << "\t" << id;
	}

	/**
	This virtual function mandates functionality for being able to save employee data

	@param employee
	@return type void, saves employee information to a txt file
	*/

	virtual void save()
	{
		Employee::write_data();

	}

	const std::string get_name() const;
	const std::string get_email() const;
	int get_id();

private:
	std::string name;
	std::string email;
	int id;
	static int next_id;

};
#endif