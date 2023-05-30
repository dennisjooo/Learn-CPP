#include <iostream>
#include "math.h"


int main()
{   
    int x{ 5 };
	int y{ 6 };

    std::cout << x << " + " << y << " is " << add(x, y) << '\n';
    
    return 0;
}