#include <vector>
#include <iostream>

int main()
{
    // no need to specify length at the declaration
    std::vector<int> v;
    std::vector<int> v2 = { 9, 7, 5, 3, 1 }; // use initializer list to initialize vector (before C++11)
    std::vector<int> v3 { 9, 7, 5, 3, 1 }; // use uniform initialization to initialize vector

    // as with std::array, the type can be omitted since C++17
    std::vector v4 { 9, 7, 5, 3, 1 }; // deduced to std::vector<int>

    v[6] = 2; // no bounds checking
    v.at(7) = 3; // does bounds checking

    // Length of vector
    std::vector v { 9, 7, 5, 3, 1 };
    std::cout << "The length is: " << v.size() << '\n'; // 5

    // Resize vector
    std::vector v { 9, 7, 5, 3, 1 };
    v.resize(3); // set length to 3
    std::cout << "The length is: " << v.size() << '\n'; // 3

    // Vector of specific length
    std::vector<int> v(5); // declare a vector of length 5
    std::vector<int> v(5, 1); // declare a vector of length 5, initialized to 1

    // Compacting bool
    std::vector<bool> v{ true, false, true, true, false };

    for (int index : v)
        std::cout << index << ' ';
    
}