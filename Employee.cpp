#include<iostream>
using namespace std;

//Employee parent class
class Employee {
	//private data members
private:
	string first_name;
	string last_name;
	string date_of_birth;

	//public data members
public:
	//parametrized constructor
	Employee(string fname, string lname,string dob)
	{
		first_name = fname;
		last_name = lname;
		date_of_birth = dob;
	}

	//A method that will display the data on console
	void Display()
	{
		cout << "Name= " << first_name << " " << last_name << endl << "Date of birth= " << date_of_birth << endl;
	}

	//Virtual data members of class
	virtual double weekly_salary() = 0;
	virtual int get_vacations() = 0;
	virtual double get_insurance() = 0;
};

//Child class professional inherits from parent class Employee
class Professional : public Employee
{
	//private data member
private:
	double salary;

public:
	//parameterized constructor
	Professional(string fname, string lname, string dob, double sal) : Employee(fname,lname,dob)
	{
		salary = sal;
	}

	//Overriding virtual methods of parent class
	double weekly_salary()
	{
		return salary / 4;
	}

	int get_vacations()
	{
		return 14;
	}

	double get_insurance()
	{
		return salary / 2;
	}
};

//Child class Nonprofessional inherits from parent class Employee
class NonProfessional : public Employee
{
private:
	double timeWorked,hourlyRate;


public:
	//Parameterized constructor
	NonProfessional(string fname,string lname , string dob, double wTime, double hRate) : Employee(fname,lname,dob)
	{
		timeWorked = wTime;
		hourlyRate = hRate;
	}

	//Overriding virtual methods of parent class
	double weekly_salary()
	{
		return timeWorked * hourlyRate;
	}

	int get_vacations()
	{
		return 14;
	}

	double get_insurance()
	{
		return weekly_salary() / 2;
	}
};

//Main function
int main()
{
	Professional emp1("Dean", "Ambrose", "1 June, 2000", 40000);
	emp1.Display();
	cout << "Weekly Salary=" << emp1.weekly_salary() << endl;
	cout << "Insurance=" << emp1.get_insurance() << endl;
	cout << "Vacations=" << emp1.get_vacations() << endl << endl;

	NonProfessional emp2("Roman", "Reigns", "25 Dec, 1990", 80, 1300);
	emp2.Display();
	cout << "Weekly Salary=" << emp1.weekly_salary() << endl;
	cout << "Insurance=" << emp1.get_insurance() << endl;
	cout << "Vacations=" << emp1.get_vacations() << endl << endl;

}