#include <iostream>

// returns true if x and y are equal, false otherwise
bool isEqual(int x, int y)
{
    return (x == y); // operator== returns true if x equals y, and false otherwise
}


int main()
{
    bool b1 { true };
    bool b2 { false };
    b1 = false;
    bool b3 {}; // default initialize to false

    bool b4 { !true }; // b4 will be initialized with the value false
    bool b5 { !false }; // b5 will be initialized with the value true

    std::cout << true << '\n'; // true evaluates to 1
    std::cout << !true << '\n'; // !true evaluates to 0

    bool b{false};
    std::cout << b << '\n'; // b is false, which evaluates to 0
    std::cout << !b << '\n'; // !b is true, which evaluates to 1
    return 0;

    std::cout << std::boolalpha; // print bools as true or false
    std::cout << true << '\n';
    std::cout << false << '\n';

    std::cout << std::noboolalpha; // turn off boolalpha
    std::cout << true << '\n';
    std::cout << false << '\n';

    // boolean input
    bool b_input{};
    std::cout << "Enter a boolean value: ";
    std::cin >> b_input; // must be 0 or 1, anything else will evaluate to false if converted to bool. boolalpha will allow true/false when needed
    std::cout << "You entered: " << b_input << '\n';

    // boolean return values in functions
    int x{ 5 };
    int y{ 7 };
    std::cout << x << " and " << y << " are equal? ";
    std::cout << isEqual(x, y); // will return true or false
}