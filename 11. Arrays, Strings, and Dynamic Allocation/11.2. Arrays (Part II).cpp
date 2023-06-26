#include <iostream>

namespace StudentNames
{
    enum StudentNames
    {
        kenny, // 0
        kyle, // 1
        stan, // 2
        butters, // 3
        cartman, // 4
        wendy, // 5
        max_students // 6
    };
}

void passArray(int prime[5]) // prime is the actual array
{
    prime[0] = 11; // so changing it here will change the original argument!
    prime[1] = 7;
    prime[2] = 5;
    prime[3] = 3;
    prime[4] = 2;
}

int main()
{   
    // Initializing an array with a list of values
    int array[5]{ 7, 4, 5 }; // only initialize first 3 elements, ifthe element is not initialized, it will be set to 0

    std::cout << array[0] << '\n';
    std::cout << array[1] << '\n';
    std::cout << array[2] << '\n';
    std::cout << array[3] << '\n';
    std::cout << array[4] << '\n';


    // Omitting the length of the array
    int array2[]{ 7, 4, 5 }; // length is 3


    // Creating the array from enum in namespace
    int testScores[StudentNames::max_students]{}; // allocate 6 integers
    testScores[StudentNames::stan] = 76;



    // Passing an array to a function ( it is passed by reference, thus if you don't want to change the original array, use const arrays)
    int prime[5]{ 2, 3, 5, 7, 11 };
    std::cout << "before passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3] << " " << prime[4] << '\n';
    passArray(prime);
    std::cout << "after passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3] << " " << prime[4] << '\n';


    
    // Size of an array (doesn't work with functions because they decay to pointers)
    int array3[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << sizeof(array3) / sizeof(array3[0]) << '\n'; // will print sizeof(int) * array length / sizeof(int) = array length

    std::cout << std::size(array3) << '\n'; // same as above

    std::cout << std::ssize(array3) << '\n'; // same as above, but returns a signed integer

    return 0;
}