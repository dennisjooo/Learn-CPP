#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

void printEmployee(const Employee& employee) // note pass by reference here
{
    std::cout << "ID:   " << employee.id << '\n';
    std::cout << "Age:  " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

Employee zeroOut()
{
    return {0, 0, 0.0}; // Alternatively {} works too. If type deduction is used, need to specify the type as well.
}

// Some struct nesting
struct Company
{
    int numberOfEmployees {};
    Employee CEO {}; // Employee is a struct within the Company struct
};

int main()
{   
    // Passing structs to functions
    Employee joe { 14, 32, 24.15 };
    Employee frank { 15, 28, 18.27 };

    // Print Joe's information
    printEmployee(joe);

    std::cout << '\n';

    // Print Frank's information
    printEmployee(frank);


    // Returning structs from functions
    Employee zeroed = zeroOut();
    printEmployee(zeroed);


    // Nested structs
    Company myCompany { 7, { 14, 32, 24.15 } };
    printEmployee(myCompany.CEO);

    return 0;
}