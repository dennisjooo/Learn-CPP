#include <iostream>

int main()
{
    std::cout << 5; // 5 (no suffix) is type int (by default)
    std::cout << 5L; // 5L is type long

    unsigned int x { 5u }; // 5u is type unsigned int
    std::cout << x;

    // Floating point literals
    std::cout << 5.0; // 5.0 (no suffix) is type double (by default)
    std::cout << 5.0f; // 5.0f is type float

    // Scientific notation
    double pi { 3.14159 }; // 3.14159 is a double literal in standard notation
    double avogadro { 6.02e23 }; // 6.02 x 10^23 is a double literal in scientific notation
    double electron { 1.6e-19 }; // 1.6 x 10^-19 is a double literal in scientific notation

    // Avoid magic numbers by using named constants
    constexpr int numClassrooms { 20 };
    constexpr int maxStudentsPerClass { 30 };
    constexpr int totalStudents{ numClassrooms * maxStudentsPerClass }; // now obvious what this 30 means

    return 0;
}