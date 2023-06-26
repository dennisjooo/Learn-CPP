#include <iostream>
#include <iterator> // for std::size
#include <cstring> // for std::strlen

int main()
{   
    // C-style strings (Avoid using them in modern C++)
    char myString[]{ "string" };
    const int length{ static_cast<int>(std::size(myString)) };
//  const int length{ sizeof(myString) / sizeof(myString[0]) }; // use instead if not C++17 capable
    std::cout << myString << " has " << length << " characters.\n";

    for (int index{ 0 }; index < length; ++index)
        std::cout << static_cast<int>(myString[index]) << ' ';

    std::cout << '\n';

    char name[20]{ "Alex" }; // only use 5 characters (4 letters + null terminator)
    std::cout << "My name is: " << name << '\n';


    // C-style strings and std::cin
    char name2[255]; // declare a large enough array to hold the largest input we expect
    std::cout << "Enter your name: ";
    std::cin >> name2; // this will overwrite the memory beyond the array!
    std::cout << "You entered: " << name2 << '\n';

    // Note: std::cin considers a space (whitespace, tabs, etc) as a terminating character, which means that it can only display a single word (even if you type many words), instead you can use std::getline

    std::cout << "Enter your full name: ";
    std::cin.ignore(32767, '\n'); // ignore up to 32767 characters until a \n is removed
    std::cin.getline(name2, 255); // read up to 255 characters into name2 array
    std::cout << "You entered: " << name2 << '\n';


    // Manipulating C-style strings
    char myString2[]{ "string" };
    std::cout << myString2 << " has " << std::size(myString2) << " characters.\n";

    myString2[0] = 'S'; // capitalize the first letter in myString
    std::cout << myString2 << '\n';

    std::cout << myString2 << " has " << std::strlen(myString2) << " characters.\n";



    return 0;
}