#include <iostream>
#include <sstream>
#include <string>

int main()
{   
    // Insertion
    std::stringstream os;
    os << "en garde!\n"; // insert "en garde!" into the stringstream

    os.str("en garde!\n"); // set the stringstream to "en garde!\n"


    // Extraction
    std::cout << os.str(); // extract the stringstream and print it to the console
    std::string strValue;
    os >> strValue; // extract the stringstream and store it in strValue
    std::cout << strValue << '\n';


    // Conversion from values to strings
    int intValue{ 12345 };
    os << intValue; // insert intValue into the stringstream
    std::string strValue2{ os.str() }; // extract the stringstream and store it in strValue2
    std::cout << strValue2 << '\n';

    // Conversion from strings to values
    std::string strValue3{ "12345" };
    int intValue2{};
    os.str(strValue3); // set the stringstream to strValue3
    os >> intValue2; // extract the stringstream and store it in intValue2
    std::cout << intValue2 << '\n';


    // Clearing the stringstream
    os.str(""); // set the stringstream to an empty string
    os.clear(); // clear the stringstream

}
