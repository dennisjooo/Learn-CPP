#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

struct Company
{
    int numberOfEmployees{};
    Employee CEO{};
};


int main()
{
    Employee joe{ 1, 34, 65000.0 };

    // Using (.) member selection operator
    ++joe.age;
    joe.wage = 68000.0;


    // Using pointer to access members (first method using dereference operator)
    Employee* ptr{ &joe };
    std::cout << (*ptr).id << '\n'; // Not great but works: First dereference ptr, then use member selection

    // Using pointer to access members (second method using arrow operator)
    std::cout << ptr->id << '\n'; // Better: First dereference ptr, then use member selection


    // Mixing pointers and non-pointers
    Company myCompany{ 7, { 14, 32, 24.15 } };
    Company* myCompanyPtr{ &myCompany };

    std::cout << myCompany.CEO.wage << '\n'; // First select myCompany, then select CEO, then select wage
    std::cout << (myCompanyPtr->CEO).wage << '\n'; // First dereference myCompany, then select CEO, then select wage
    return 0;
}