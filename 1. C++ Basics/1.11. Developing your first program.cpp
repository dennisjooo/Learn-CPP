#include <iostream>

int main()
{
    std::cout << "Enter an integer: "; // ask user for an integer

    int userInput{};

    std::cin >> userInput; // read integer from console and store it in userInput

    std::cout << "Double " << userInput << " is: " << userInput * 2 << '\n';

    std::cout << "Triple " << userInput << " is: " << userInput * 3 << '\n';

    return 0;
}