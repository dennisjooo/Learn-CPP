#include <utility> // for std::pair


template <typename T, typename U> // You can add default types here say T=int, U=double etc
struct Pair
{
    T first{};
    U second{};
};

// Here's a deduction guide for our Pair (needed in C++17)
// Pair objects initialized with arguments of type T and U should deduce to Pair<T, U>
template <typename T, typename U>
Pair(T, U) -> Pair<T, U>;

// Note: Technically, we don't need to write the above deduction guide, because the compiler will generate one for us if we're using C++20 or later that supports P1816


int main()
{
    [[maybe_unused]]std::pair<int, int> p1{ 1, 2 }; // explicitly specify class template std::pair<int, int> (C++11 onward)
    [[maybe_unused]]std::pair p2{ 1, 2 };           // CTAD used to deduce std::pair<int, int> from the initializers (C++17)


    // Our Pair
    [[maybe_unused]]Pair<int, int> p3{ 1, 2 }; // explicitly specify class template Pair<int, int> (C++11 onward)
    [[maybe_unused]]Pair p4{ 1, 2 };           // CTAD used to deduce Pair<int, int> from the initializers (C++17)

    return 0;
}