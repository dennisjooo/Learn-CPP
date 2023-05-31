#include <iostream>
#include <string_view>

void printSV(std::string_view str) // now a std::string_view
{
    std::cout << str << '\n';
}

void printString(std::string str)
{
    std::cout << str << '\n';
}

int main()
{   
    // string_view provides a lightweight, read-only view into a string, copying the string is not required as it is slower
    std::string_view s{ "Hello, world!" }; // now a std::string_view
    printSV(s);

    // constexpr string_view
    constexpr std::string_view s{ "Hello, world!" };
    std::cout << s << '\n'; // s will be replaced with "Hello, world!" at compile-time

    // string to string_view
    std::string s{ "Hello, world" };
    std::string_view sv{ s }; // Initialize a std::string_view from a std::string
    std::cout << sv << '\n';

    printSV(s); // implicitly convert a std::string to std::string_view

    // string_view to string
    std::string_view sv2{ "balloon" };

    std::string str2{ sv2}; // okay, we can create std::string using std::string_view initializer

    // printString(sv);   // compile error: won't implicitly convert std::string_view to a std::string

    printString(static_cast<std::string>(sv2)); // okay, we can explicitly cast a std::string_view to a std::string

    // string_view literals
    using namespace std::literals; // easiest way to access the s and sv suffixes

    std::cout << "foo\n";   // no suffix is a C-style string literal
    std::cout << "goo\n"s;  // s suffix is a std::string literal
    std::cout << "moo\n"sv; // sv suffix is a std::string_view literal

    return 0;
}