#include <iostream>

class DateClass
{
public:
    int m_year {}; //m_ prefix to indicate member variable
    int m_month {};
    int m_day {};

    void print() // defines a member function named print()
    {
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }
};

class Employee
{
public:
    std::string m_name {};
    int m_id {};
    double m_wage {};

    // Print employee information to the screen
    void print()
    {
        std::cout << "Name: " << m_name <<
                "  Id: " << m_id <<
                "  Wage: $" << m_wage << '\n';
    }
};

class IntPair
{
public:
	int m_first{};
	int m_second{};

	void set(int first, int second)
	{
		m_first = first;
		m_second = second;
	}
	void print()
	{
		std::cout << "Pair(" << m_first << ", " << m_second << ")\n";
	}
};



int main()
{   
    // DateClass class
    DateClass today { 2020, 10, 14 };

    today.m_day = 16; // use member selection operator to select a member variable of the class
    today.print(); // use member selection operator to call a member function of the class


    // Employee class
    // Declare two employees
    Employee alex { "Alex", 1, 25.00 };
    Employee joe { "Joe", 2, 22.25 };

    // Print out the employee information
    alex.print();
    joe.print();


    // IntPair
    IntPair p1;
	p1.set(1, 1);

	IntPair p2 { 2, 2 };

	p1.print();
	p2.print();
    return 0;
}