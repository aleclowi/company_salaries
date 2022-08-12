#include<iostream>
#include<string>
#include <fstream>
#include "Employee.h"
#include "HourlyWorker.h"

using namespace std;


int main()
{
	char choice;
	do
	{
		cout << "What would you like to do?\n" << "C - Create Employee\n" << "D - Display Current Directory\n"
			<< "H - Set Hours\n" << "P - Print Payroll\n" << "Quit (all other inputs)";
		cin >> choice;
		if (choice == 'C')
		{
			char employeeType;
			cout << "What type of employee?\n" << "S - Salaried\n" << "H - Hourly\n" << "Abort (all other inputs)?";
			cin >> employeeType;
			if(employeeType == 'S')
			{

			}
			else if(employeeType == 'H')
			{

			}
			else
			{
				break;
			}
		}
		else if (choice == 'D')
		{

		}
		else if(choice == 'H')
		{

		}
		else if (choice == 'P')
		{
			ifstream file;
			string files = "employee0.txt";
			file >> files;
			file.open(files);
			Employee e1(file);
			e1.print();
			cout << '\n';
		}
		else
		{
			cout << "creation aborted";
		}

	} while (choice == 'C' || choice == 'D' || choice == 'H' || choice == 'P');

	return 0;
}