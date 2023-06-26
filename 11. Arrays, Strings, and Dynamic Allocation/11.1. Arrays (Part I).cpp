#include <iostream>

struct Rectangle
{
    int length{};
    int width{};
};

int main()
{   
    // Arrays are a collection of elements of the same type
    int prime[5]{}; // hold the first 5 prime numbers
    prime[0] = 2; // The first element has index 0
    prime[1] = 3;
    prime[2] = 5;
    prime[3] = 7;
    prime[4] = 11; // The last element has index 4 (array length-1)

    std::cout << "The lowest prime number is: " << prime[0] << '\n';
    std::cout << "The sum of the first 5 primes is: " << prime[0] + prime[1] + prime[2] + prime[3] + prime[4] << '\n';

    // Arrays can also be initialized when they are declared
    double batteryLifeInHours[3]{ 2.0, 3.0, 4.5 };

    std::cout << "The average battery life is " << (batteryLifeInHours[0] + batteryLifeInHours[1] + batteryLifeInHours[2]) / 3.0 << " hour(s)\n";


    // Structs can also be used to create arrays
    Rectangle rects[5]{}; // declare an array of 5 Rectangle


    // Fixed-length array initialisation (Must be fixed at compile time)
    // using a literal constant
    int numberOfLessonsPerDay[7]{}; // Ok

    // using a constexpr symbolic constant
    constexpr int daysPerWeek{ 7 };
    int numberOfLessonsPerDay[daysPerWeek]{}; // Ok

    // using an enumerator
    enum DaysOfWeek
    {
        monday,
        tuesday,
        wednesday,
        thursday,
        friday,
        saturday,
        sunday,

        maxDaysOfWeek
    };
    int numberOfLessonsPerDay[maxDaysOfWeek]{}; // Ok

    // using a macro
    #define DAYS_PER_WEEK 7
    int numberOfLessonsPerDay[DAYS_PER_WEEK]{}; // Works, but don't do this (use a constexpr symbolic constant instead)
    return 0;
}