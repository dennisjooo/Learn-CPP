#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    if (x >= 0)
    { // enclosed this inner if statement with a brace
        if (x <= 20)
            std::cout << x << " is between 0 and 20\n";
        else // attached to inner if statement
            std::cout << x << " is greater than 20\n";
    }
    else // attached to outer if statement
        std::cout << x << " is negative\n";

    // flattened version of the above nested if statement
    if (x < 0)
        std::cout << x << " is negative\n";
    else if (x <= 20) // only executes if x >= 0
        std::cout << x << " is between 0 and 20\n";
    else // only executes if x > 20
        std::cout << x << " is greater than 20\n";

    return 0;

    // be wary too of null statements, dangling else, the comma operator, and equality vs assignment
}