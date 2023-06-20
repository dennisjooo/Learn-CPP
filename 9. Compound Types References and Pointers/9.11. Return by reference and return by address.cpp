#include <iostream>
#include <string>

const std::string& getProgramName() // returns a const reference
{
    static const std::string s_programName { "Calculator" }; // has static duration, destroyed at end of program. Must outlive the function call or else might return a dangling reference

    return s_programName;
}

const int& getNextId()
{
    static int s_x{ 0 };
    ++s_x;
    return s_x;
}

// Takes two std::string objects, returns the one that comes first alphabetically
const std::string& firstAlphabetical(const std::string& a, const std::string& b)
{
	return (a < b) ? a : b; // We can use operator< on std::string to determine which comes first alphabetically
}

// takes two integers by non-const reference, and returns the greater by reference
int& max(int& x, int& y)
{
    return (x > y) ? x : y;
}

int main()
{
    std::cout << "This program is named " << getProgramName();


    // Returns reference to a local variable, but this defeats the purpose of returning a reference since the local variable will make a copy of the value returned by reference

    const int id1 { getNextId() }; // id1 is a normal variable now and receives a copy of the value returned by reference from getNextId()
    const int id2 { getNextId() }; // id2 is a normal variable now and receives a copy of the value returned by reference from getNextId()

    std::cout << id1 << id2 << '\n';


    // Returning the reference params by reference
    std::string hello { "Hello" };
	std::string world { "World" };

	std::cout << firstAlphabetical(hello, world) << '\n';


    // Changing value via returned reference
    int a{ 5 };
    int b{ 6 };

    max(a, b) = 7; // sets the greater of a or b to 7

    std::cout << a << b << '\n';


    // Return by address can be done but is not recommended. It has similar characteristics to return by reference, but it is more dangerous because the caller must remember to delete the pointer when they are done with it, especially with nullptr (need to be checked before dereferencing etc.)

    return 0;
}