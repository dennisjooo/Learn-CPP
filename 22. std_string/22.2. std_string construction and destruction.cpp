#include <iostream>
#include <sstream>
#include <string>

template <typename T>
inline std::string ToString(T tX)
{
    std::ostringstream oStream;
    oStream << tX;
    return oStream.str();
}

template <typename T>
inline bool FromString(const std::string& sString, T& tX)
{
    std::istringstream iStream(sString);
    return !(iStream >> tX).fail(); // extract value into tX, return success or not
}

int main()
{   
    // Using ostringstream to convert a value to a string
    std::string sFour{ ToString(4) };
    std::string sSixPointSeven{ ToString(6.7) };
    std::string sA{ ToString('A') };
    std::cout << sFour << '\n';
    std::cout << sSixPointSeven << '\n';
    std::cout << sA << '\n';

    // Possible to use std::to_string() to convert a value to a string
    std::string sFour2{ std::to_string(4) };
    std::cout << sFour2 << '\n';


    // Using istringstream to convert a string to a value
    int nValue;
    if (FromString("4", nValue))
        std::cout << nValue << '\n';
    double dValue;
    if (FromString("6.7", dValue))
        std::cout << dValue << '\n';

    
}