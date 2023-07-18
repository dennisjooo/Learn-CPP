#include <iostream>
#include <string>

int main()
{   
    // Character access
    std::string sSource{ "abcdefg" };
    std::cout << sSource[5] << '\n';
    sSource[5] = 'X';
    std::cout << sSource << '\n';

    // Character access with at()
    std::string sSource2{ "abcdefg" };
    std::cout << sSource2.at(5) << '\n';
    sSource2.at(5) = 'X';
    std::cout << sSource2 << '\n';


    // Conversion to C-style array
    std::string sSource3{ "abcdefg" };
    std::cout << sSource3.c_str() << '\n';
    const char* pszBuffer{ sSource3.c_str() };
}