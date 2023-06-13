#include <iostream>

int max(int x, int y) // x and y enter scope here
{
    // assign the greater of x or y to max
    int max{ (x > y) ? x : y }; // max enters scope here

    return max;
} // max, y, and x leave scope here

int main()
{
    int i { 5 }; // i enters scope here
    double d { 4.0 }; // d enters scope here
    int x { 5 }; // x enters scope and is created here

    { // nested block
        int y { 7 }; // y enters scope and is created here

        int x { 3 }; // this identifier x refers to a different object than the previous x

        // x and y are both in scope here
        std::cout << x << " + " << y << " = " << x + y << '\n';
    } // y goes out of scope and is destroyed here

    // y can not be used here because it is out of scope in this block
    

    // Prompt user for integer
    std::cout << "Enter an integer: ";
    int smaller{ };
    std::cin >> smaller;

    // Prompt user for another integer
    std::cout << "Enter a larger integer: ";
    int larger{ };
    std::cin >> larger;

    // Determine larger and smaller values
    if (smaller > larger) // smaller and larger are in scope here
    {
        // Swap smaller and larger so smaller is smaller and larger is larger
        int temp{ larger }; // create a temporary variable to hold the larger value
        larger = smaller;
        smaller = temp;
    } // temp goes out of scope and is destroyed here

    std::cout << "The smaller value is " << smaller << '\n';
    std::cout << "The larger value is " << larger << '\n';

    return 0;
} // d and i go out of scope here