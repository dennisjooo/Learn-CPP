#include <iostream>

double getValue()
{
    std::cout << "Enter a double value: ";
    double value{};
    std::cin >> value;
    return value;
}

char getOperator()
{
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char op{};
    std::cin >> op;
    return op;
}

void printResult(double x, char op, double y)
{
    if (op == '+')
        std::cout << x << " + " << y << " is " << x + y << '\n';
    else if (op == '-')
        std::cout << x << " - " << y << " is " << x - y << '\n';
    else if (op == '*')
        std::cout << x << " * " << y << " is " << x * y << '\n';
    else if (op == '/')
        std::cout << x << " / " << y << " is " << x / y << '\n';
    else // otherwise print error message
        std::cout << "Invalid operator\n";
}

int main()
{
    double x{ getValue() };
    double y{ getValue() };

    char op{ getOperator() };

    printResult(x, op, y);

    return 0;
}