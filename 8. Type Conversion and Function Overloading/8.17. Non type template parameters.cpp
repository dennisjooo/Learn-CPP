#include <iostream>

template <auto N> // declare a non-type template parameter of type auto named N
void print()
{
    std::cout << N; // use value of N here
}

int main()
{
    print<5>(); // 5 is our non-type template argument

    print<'a'>(); // 'a' is our non-type template argument

    return 0;
}