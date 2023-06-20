#include <iostream>
#include <string>

void printValue(std::string& y) // type changed to std::string&
{
    std::cout << y << '\n';
} // y is destroyed here

void addOne(int& y) // y is a reference to x
{
    ++y; // this modifies the actual object x
}

void printValue(const int& y) // y is now a const reference
{
    std::cout << y << '\n';
}

#define isSmall(T) (sizeof(T) <= 2 * sizeof(void*))

struct S
{
    double a, b, c;
};

int main()
{
    std::string x { "Hello, world!" };

    printValue(x); // x is now passed by reference into reference parameter y (inexpensive)


    // Modify the value of x through the reference parameter y
    int a { 5 };

    std::cout << a << '\n';

    addOne(a); // a is passed by reference, so this modification will be visible to the caller

    std::cout << a << '\n';
    // Note, we cannot pass in literal values as well as const values into a non-const lvalue reference parameter

    const int b { 6 };
    printValue(b); // okay: we can pass a const value into a const reference parameter, this uses the second printValue() function


    // Use references if the object is expensive to copy and you don’t want to modify the original object
    std::cout << std::boolalpha; // print true or false rather than 1 or 0
    std::cout << isSmall(int) << '\n'; // true
    std::cout << isSmall(double) << '\n'; // true
    std::cout << isSmall(S) << '\n'; // false


    return 0;
}