#include <iostream>
#include <string>

int main()
{
    std::string name { "Alex" };
    std::cout << "My name is: " << name << '\n';

    std::string empty{ };
    std::cout << '[' << empty << ']';

    // string input
    std::cout << "Enter your full name: ";
    std::string name2{};
    std::getline(std::cin, name2); // read a full line of text into name
    std::cout << "Your name is: " << name2 << '\n';

    // std::ws
    std::cout << "Pick 1 or 2: ";
    int choice{};
    std::cin >> choice;

    std::cout << "Now enter your name: ";
    std::string name3{};
    std::getline(std::cin >> std::ws, name3); // note: added std::ws here, used to ignore leading whitespace

    std::cout << "Hello, " << name << ", you picked " << choice << '\n';
    
    // string length
    std::string string1{ "Hello, world!" };
    std::cout << string1 << " has " << string1.length() << " characters\n"; //.length() returns the number of characters in the string, it is a member function of the string class. It is an unsigned int

    // std::cout << string1 << " has " << std::ssize(string1) << " characters\n"; // std::ssize() returns the number of characters in the string, it is a function in the std namespace, somehow it shows error :)

    // string literals
    using namespace std::literals; // easiest way to access the s and sv suffixes

    std::cout << "foo\n";   // no suffix is a C-style string literal
    std::cout << "goo\n"s;  // s suffix is a std::string literal
    std::cout << "moo\n"sv; // sv suffix is a std::string_view literal


    return 0;
}