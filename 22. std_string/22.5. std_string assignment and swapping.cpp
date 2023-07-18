#include <iostream>
#include <string>

int main()
{   
    // Assignment
    std::string sString;

    // Assign a string value
    sString = std::string("One");
    std::cout << sString << '\n';

    const std::string sTwo("Two");
    sString.assign(sTwo);
    std::cout << sString << '\n';

    // Assign a C-style string
    sString = "Three";
    std::cout << sString << '\n';

    sString.assign("Four");
    std::cout << sString << '\n';

    // Assign a char
    sString = '5';
    std::cout << sString << '\n';

    // Chain assignment
    std::string sOther;
    sString = sOther = "Six";
    std::cout << sString << ' ' << sOther << '\n';

    /// Assigning a substring
    const std::string sSource("abcdefg");
    std::string sDest;

    sDest.assign(sSource, 2, 4); // assign a substring of source from index 2 of length 4
    std::cout << sDest << '\n';

    sDest.assign(4, 'X'); // assign 4 copies of 'X'
    std::cout << sDest << '\n';


    // Swapping
    std::string sOne("One");
    std::string sTwo2("Two");

    std::cout << sOne << ' ' << sTwo2 << '\n';
    
    swap(sOne, sTwo2);

    std::cout << sOne << ' ' << sTwo2 << '\n';

    sOne.swap(sTwo2);

    std::cout << sOne << ' ' << sTwo2 << '\n';
}