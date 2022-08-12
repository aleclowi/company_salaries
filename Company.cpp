#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vector>
#include "Employee.h"
#include "HourlyWorker.h"
#include "SalariedWorker.h"
#include "Company.h"


Employee::Employee(std::string _name, std::string _email) : name(_name), email(_email), id(0)
{

}
Employee::Employee(std::ifstream& inFile)
{
    /*
      std::string type;
      inFile >> type;
      inFile >> name;
      std::string lastName;
      inFile >> lastName;
      name = name + " " + lastName;
      inFile >> email;
      inFile >> id;
      */
    std::cout << std::endl;
    std::string line;
    std::string type;
    int hours, rate;
    std::string lastName;
    while (getline(inFile, line)) {
        std::stringstream ss(line);

        ss >> type;
        ss >> name;
        ss >> lastName;
        ss >> email;
        ss >> id;
        ss >> hours;
        ss >> rate;
    }

}

const std::string Employee::get_name() const
{
    return name;
}

const std::string Employee::get_email() const
{
    return email;
}
int Employee::get_id()
{
    return id;
}
void Employee::print()
{
    std::cout << Employee::get_name() << "\t" << Employee::get_email() << "\t" << Employee::get_id();
}

void Employee::write_data()
{
    std::ostringstream sout;
    //Number of files goes here, then create a newFile string that stores the number of files as a string
    //to be used in the new file name
    sout << id;
    std::string newID = sout.str();
    std::ofstream outfile;// declaration of file pointer named outfile
    outfile.open("employee" + newID + ".txt"); // opens file for output
    //Copy the above loop to place the output into the file. 
    //The only thing different here is that now we are using outfile operator instead of cout
    //to store the data into the file
    outfile << Employee::get_name() << "\t" << Employee::get_email() << "\t" << Employee::get_id() << '\n';
    outfile.close();
}


/*FUNCTION BODIES FOR HOURLYWORKER.H*/

HourlyWorker::HourlyWorker(std::string name, std::string email, int _hours, int _rate) : hours(_hours), rate(_rate), Employee(std::move(name), std::move(email)) { }

HourlyWorker::HourlyWorker(std::ifstream& inFile) : Employee(inFile)
{
    inFile >> hours;
    inFile >> rate;
    inFile.close();
}

int HourlyWorker::get_rate()
{
    return rate;
}
int HourlyWorker::get_hours()
{
    return hours;
}

void HourlyWorker::set_hours()
{
    hours += hours;
}

SalariedWorker::SalariedWorker(std::string name, std::string email, double salary) :
    Employee(std::move(name), std::move(email)), salary(salary)
{

}

SalariedWorker::SalariedWorker(std::ifstream& inFile) : Employee(inFile)
{
    inFile >> salary;
    inFile.close();
}

Company::Company(std::vector<std::shared_ptr<Employee>> employee) :  employee(employee)
{

}