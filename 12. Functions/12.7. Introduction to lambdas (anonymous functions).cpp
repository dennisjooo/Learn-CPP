#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <functional> // for std::function

// We don't know what fn will be. std::function works with regular functions and lambdas.
void repeat(int repetitions, const std::function<void(int)>& fn)
{
  for (int i{ 0 }; i < repetitions; ++i)
  {
    fn(i);
  }
}

int main()
{
    constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

    // Define the function right where we use it.
    const auto found{ std::find_if(arr.begin(), arr.end(),
                            [](std::string_view str) // here's our lambda, no capture clause
                            {
                                return (str.find("nut") != std::string_view::npos);
                            }) };

    if (found == arr.end())
    {
        std::cout << "No nuts\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }


    // Function literal lambda
    auto isEven{
    [](int i)
    {
        return ((i % 2) == 0);
    }
    };


    // A regular function pointer. Only works with an empty capture clause (empty []).
    double (*addNumbers1)(double, double){
        [](double a, double b) {
        return (a + b);
        }
    };

    // Using std::function. The lambda could have a non-empty capture clause (discussed next lesson).
    std::function addNumbers2{ // note: pre-C++17, use std::function<double(double, double)> instead
        [](double a, double b) {
        return (a + b);
        }
    };

    addNumbers2(3, 4);

    // Using auto. Stores the lambda with its real type.
    auto addNumbers3{
        [](double a, double b) {
        return (a + b);
        }
    };

    addNumbers3(5, 6);

    // A std::function. Works with any lambda, regardless of capture clause.
    repeat(3, [](int i) {
        std::cout << i << '\n';
    });



    // Generic lambda
    auto add {[](auto x, auto y) { return x + y; }};
    return 0;



    // Generic lambda and static variables
    auto counter {[](auto x) {
        static int count = 0;
        count += x;
        return count;
        }
    };

    std::cout << counter(1) << '\n';
    std::cout << counter(2) << '\n';
    std::cout << counter(3) << '\n';

    std::cout << counter(1.1) << '\n';
    std::cout << counter(2.2) << '\n';
    std::cout << counter(3.3) << '\n';
    


    // Explicitly specifying the return type
    auto add2 {[](auto x, auto y) -> double { //Explicitly specifying the return type
        return x + y; }
    };
}