#include <iostream>

// Full implementation of the getUserInput function
int getUserInput()
{
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;

    return input;
}

// Full implementation of the getMathematicalOperation function
char getMathematicalOperation()
{
    std::cout << "Enter '+', '-', '*', or '/': ";
    char operation{};
    std::cin >> operation;

    return operation;
}

// Full implementation of the calculateResult function
int calculateResult(int x, char operation, int y)
{
    if (operation == '+')
        return x + y;
    else if (operation == '-')
        return x - y;
    else if (operation == '*')
        return x * y;
    else if (operation == '/')
        return x / y;
    else // This should never be reached, but we'll write it as a failsafe.
        std::cout << "calculateResult() error: Unhandled case: " << operation << '\n';
    return 0;
}

// Full implementation of the printResult function
void printResult(int x, int y, int result, char operation)
{
    std::cout << x << ' ' << operation << ' ' << y << " is " << result << '\n';
}

int main()
{
    // Get first number from user
    int value{ getUserInput() };
    std::cout << value << '\n';

    // Get mathematical operation from user
    char op{ getMathematicalOperation() };

    // Get second number from user
    int value2{ getUserInput() }; 
    std::cout << value2 << '\n';

    // Calculate result
    int result{ calculateResult(value, op, value2) };

    // Print result
    printResult(value, value2, result, op);

    return 0;
}