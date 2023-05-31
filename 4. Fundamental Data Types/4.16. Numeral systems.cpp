#include <iostream>
#include <bitset> // for std::bitset

int main()
{   
    // Octal literals
    int x{ 012 }; // 0 before the number means this is octal
    std::cout << x << '\n';

    // Hexadecimal literals
    int y{ 0xF }; // 0x before the number means this is hexadecimal
    std::cout << y << '\n';

    // Binary literals
    int bin{};        // assume 16-bit ints
    bin = 0b1;        // assign binary 0000 0000 0000 0001 to the variable
    bin = 0b11;       // assign binary 0000 0000 0000 0011 to the variable
    bin = 0b1010;     // assign binary 0000 0000 0000 1010 to the variable
    bin = 0b11110000; // assign binary 0000 0000 1111 0000 to the variable

    // Digit separators
    int binsep { 0b1011'0010 };  // assign binary 1011 0010 to the variable
    long value { 2'132'673'462 }; // much easier to read than 2132673462

    // Outputing in octal and hexadecimal
    int z { 12 };
    std::cout << z << '\n'; // decimal (by default)
    std::cout << std::hex << z << '\n'; // hexadecimal
    std::cout << z << '\n'; // now hexadecimal
    std::cout << std::oct << z << '\n'; // octal
    std::cout << std::dec << z << '\n'; // return to decimal
    std::cout << z << '\n'; // decimal

    // Outputing in binary
    std::cout << std::bitset<4>{ 0b1010 } << '\n'; // print 1010 in binary, the std::bitset<4> forces cout to print at least 4 digits

    std::cout << std::bitset<8>{ 0b1010 } << '\n'; // print 00001010 in binary

    return 0;
}