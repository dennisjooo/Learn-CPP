#include <iostream> // angle brackets tell the preprocessor to look for the file in the compiler's include path
#include "add.h" // add.h is located in the same directory as main.cpp, use double quotes to tell the preprocessor to look for it in the current directory

int getInteger(); // needed so main.cpp knows that getInteger() is a function defined elsewhere

int main()
{   
    int x{ getInteger() };
	int y{ getInteger() };

    std::cout << x << " + " << y << " is " << add(x, y) << '\n';
    
    return 0;
}