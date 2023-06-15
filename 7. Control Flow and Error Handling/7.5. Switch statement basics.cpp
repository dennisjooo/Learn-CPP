#include <iostream>

void printDigitName(int x)
{
    switch (x) // x is evaluated to produce value 2
    {
        case 1:
            std::cout << "One";
            return;
        case 2: // which matches the case statement here
            std::cout << "Two"; // so execution starts here
            return; // and then we return to the caller
        case 3:
            std::cout << "Three";
            return;
        case 4:
            std::cout << "Four";
            break; // break ends the switch block
        default: // which does not match to any case labels
            std::cout << "Unknown"; // so execution starts here
            return; // and then we return to the caller
    }
}

int main()
{
    printDigitName(2);
    std::cout << '\n';

    return 0;
}