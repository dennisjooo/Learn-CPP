#include <array>
#include <algorithm> // for std::sort
#include <iostream>

// printArray is a template function
template <typename T, std::size_t size> // parameterize the element type and size
void printArray(const std::array<T, size>& myArray)
{
    for (auto element : myArray)
        std::cout << element << ' ';
    std::cout << '\n';
}

struct House
{
    int number{};
    int stories{};
    int roomsPerStory{};
};

int main()
{
    std::array<int, 3> myArray; // declare an integer array with length 3

    std::array<int, 5> myArray = { 9, 7, 5, 3, 1 }; // initializer list
    std::array<int, 5> myArray2 { 9, 7, 5, 3, 1 }; // list initialization


    // Type deduced by compiler
    std::array myArray { 9, 7, 5, 3, 1 }; // The type is deduced to std::array<int, 5>
    std::array myArray { 9.7, 7.31 }; // The type is deduced to std::array<double, 2>


    // C-style to array (expensive)
    auto myArray1 { std::to_array<int, 5>({ 9, 7, 5, 3, 1 }) }; // Specify type and size
    auto myArray2 { std::to_array<int>({ 9, 7, 5, 3, 1 }) }; // Specify type only, deduce size
    auto myArray3 { std::to_array({ 9, 7, 5, 3, 1 }) }; // Deduce type and size


    // Size and sort
    std::array myArray { 7, 3, 1, 9, 5 };
    std::cout << "The length is: " << myArray.size() << '\n'; // 5

    std::sort(myArray.begin(), myArray.end()); // sort the array forwards


    // Manual indexing
    std::array myArray { 7, 3, 1, 9, 5 };

    for (std::size_t i{ 0 }; i < myArray.size(); ++i) // size_t in this case is size_type (unsigned int)
        std::cout << myArray[i] << ' ';

    std::cout << '\n';


    // Array of structs
    std::array<House, 3> houses{};

    houses[0] = { 13, 4, 30 };
    houses[1] = { 14, 3, 10 };
    houses[2] = { 15, 3, 40 };

    for (const auto& house : houses)
    {
        std::cout << "House number " << house.number
                  << " has " << (house.stories * house.roomsPerStory)
                  << " rooms\n";
    }

    // Can also be initialized like this
    std::array<House, 3> houses
    {
        {
            { 13, 4, 30 },
            { 14, 3, 10 },
            { 15, 3, 40 }
        }
    };
    return 0;

}