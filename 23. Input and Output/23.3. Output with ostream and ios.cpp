#include <iostream>
#include <iomanip>

int main()
{
    // Formatting output
    std::cout << "Formatting output" << '\n';
    std::cout << std::hex << 100 << '\n'; // hex is a manipulator that changes the base of the output stream to hexadecimal

    // Formatting output with flags
    std::cout << "Formatting output with flags" << '\n';
    std::cout.setf(std::ios::showpos); // setf() sets the specified flags
    std::cout << 27 << '\n';
    std::cout.unsetf(std::ios::showpos); // unsetf() unsets the specified flags


    // Precision and notation
    std::cout << "Precision and notation" << '\n';

    std::cout << std::scientific << 123.23 << '\n'; // scientific is a manipulator that changes the notation of the output stream to scientific

    std::cout << std::fixed << 123.23 << '\n'; // fixed is a manipulator that changes the notation of the output stream to fixed
    
    std::cout << std::defaultfloat << 123.23 << '\n'; // defaultfloat is a manipulator that changes the notation of the output stream to default


    // Width, fill, and alignment
    std::cout << "Width, fill, and alignment" << '\n';
    
    std::cout << std::setw(10) << 123 << '\n'; // setw() is a manipulator that sets the width of the output stream

    std::cout << std::setfill('X') << std::setw(10) << 123 << '\n'; // setfill() is a manipulator that sets the fill character of the output stream

    std::cout << std::left << std::setw(10) << 123 << '\n'; // left is a manipulator that sets the alignment of the output stream to left

    std::cout << std::right << std::setw(10) << 123 << '\n'; // right is a manipulator that sets the alignment of the output stream to right

}