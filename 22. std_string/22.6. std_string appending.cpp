#include <iostream>
#include <string>


int main()
{
    // Appending
    std::string sString{"one"};

    sString += std::string{" two"};

    std::string sThree{" three"};
    sString.append(sThree);

    std::cout << sString << '\n';

    // Appending a C-style string
    sString += " four";
    std::cout << sString << '\n';

    // Push back
    sString.push_back('5');
    std::cout << sString << '\n';

    // Chain appending
    std::string sOther{" six"};
    sString += sOther += " seven";
    std::cout << sString << '\n';
}