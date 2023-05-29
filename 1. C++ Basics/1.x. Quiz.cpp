#include <iostream>

int main()
{   
    // Zero initialize variables
    int num1 {}, num2 {};

    // Prompt user to enter a number
    std::cout << "Enter a number: ";
    
    // Store the number in num1
    std::cin >> num1;

    // Prompt user to enter another number
    std::cout << "Enter another number: ";

    // Store the number in num2
    std::cin >> num2;

    // Print numbers
    std::cout << "You entered " << num1 << " and " << num2 << '\n';

    // Addition and subtraction
    std::cout << num1 << " + " << num2 << " is " << num1 + num2 << '\n';
    std::cout << num1 << " - " << num2 << " is " << num1 - num2 << '\n';

    return 0;
}