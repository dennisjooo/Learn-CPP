#include <iostream>

int main()
{
    std::cout << "Hello world!\n"; // tabbed in one tab (4 spaces)
    std::cout << "Nice to meet you.\n"; // tabbed in one tab (4 spaces)

    std::cout << 3 + 4
    + 5 + 6
    * 7 * 8; // for readability, you can break up long lines of code

    // Aligning for assignment
    int cost          {57};
    int pricePerItem  {24};
    int value         {5};
    int numberOfItems {17};

    std::cout << "Hello world!\n";                  // cout lives in the iostream library
    std::cout << "It is very nice to meet you!\n";  // these comments are easier to read
    std::cout << "Yeah!\n";                         // especially when all lined up

    // cout lives in the iostream library
    std::cout << "Hello world!\n";

    // these comments are easier to read
    std::cout << "It is very nice to meet you!\n";

    // when separated by whitespace
    std::cout << "Yeah!\n";
}