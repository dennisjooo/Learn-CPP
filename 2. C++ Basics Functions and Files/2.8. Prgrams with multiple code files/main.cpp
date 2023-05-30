#include <iostream>

int add(int x, int y); // needed so main.cpp knows that add() is a function defined elsewhere

int getInteger(); // needed so main.cpp knows that getInteger() is a function defined elsewhere

int main()
{   
    int x{ getInteger() };
	int y{ getInteger() };

    std::cout << x << " + " << y << " is " << add(x, y) << '\n';
    
    return 0;
}