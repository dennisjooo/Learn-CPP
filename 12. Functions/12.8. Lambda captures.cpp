#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <string>
#include <functional>

void myInvoke(const std::function<void()>& fn)
{
    fn();
}


int main()
{
    // Lambda capture
    std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

    std::cout << "search for: ";

    std::string search{};
    std::cin >> search;

    // Capture @search                                vvvvvv (captured as const value)
    auto found{ std::find_if(arr.begin(), arr.end(), [search] (std::string_view str) {
        return (str.find(search) != std::string_view::npos);
    }) };

    if (found == arr.end())
    {
        std::cout << "Not found\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }



    // Mutable Lambda capture
    int ammo{ 10 };

    auto shoot{
        // Added mutable after the parameter list. (mutable but persistent and doesn't change the original value)
        [ammo]() mutable {
        // We're allowed to modify ammo now
        --ammo;

        std::cout << "Pew! " << ammo << " shot(s) left.\n";
        }
    };

    shoot();
    shoot();

    std::cout << ammo << " shot(s) left\n";


    // Lambda capture by reference
    auto shoot2{
        // We don't need mutable anymore
        [&ammo]() { // &ammo means ammo is captured by reference
        // Changes to ammo will affect main's ammo
        --ammo;

        std::cout << "Pew! " << ammo << " shot(s) left.\n";
        }
    };

    shoot2();

    std::cout << ammo << " shot(s) left\n";



    // Default capture
    std::array areas{ 100, 25, 121, 40, 56 };

    int width{};
    int height{};

    std::cout << "Enter width and height: ";
    std::cin >> width >> height;

    auto found2{ std::find_if(areas.begin(), areas.end(),
                            [=](int knownArea) { // will default capture width and height by value ('&' will capture by reference)
                                return (width * height == knownArea); // because they're mentioned here
                            }) };

    if (found2 == areas.end())
    {
        std::cout << "I don't know this area :(\n";
    }
    else
    {
        std::cout << "Area found :)\n";
    }


    // std::reference_wrapper (std::ref)
    int i{ 0 };

    // Increments and prints its local copy of @i.
    auto count{ [i]() mutable {
      std::cout << ++i << '\n';
    } };

    // std::ref(count) ensures count is treated like a reference
    // thus, anything that tries to copy count will actually copy the reference
    // ensuring that only one count exists
    myInvoke(std::ref(count));
    myInvoke(std::ref(count));
    myInvoke(std::ref(count));
  return 0;
}