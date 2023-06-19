#include <iostream>

void print(int x=2, int y=4) // 2 & 4 are the default argument. Need to use = to specify default argument, no {} or ()
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

void add(int x=3, int y=4, int z=5);


int main()
{
    print(1, 2); // y will use user-supplied argument 2
    print(3); // y will use default argument 4, as if we had called print(3, 4)

    add(1, 2, 3); // all user-supplied arguments, no defaults used

}

void add(int x, int y, int z) // No default arguments here (only in declaration because it cannot be redeclared)
{
    std::cout << x << " + " << y << " + " << z << " = " << x + y + z << '\n';
}