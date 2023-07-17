#include <algorithm> // std::min_element and std::max_element
#include <iostream>
#include <list>
#include <numeric> // std::iota
#include <vector>

int main()
{
    std::list<int> li(6);
    // Fill li with numbers starting at 0.
    std::iota(li.begin(), li.end(), 0);


    // Print the minimum and maximum elements in li.
    std::cout << *std::min_element(li.begin(), li.end()) << ' '
              << *std::max_element(li.begin(), li.end()) << '\n';


    // Insert 42 next to 3
    auto it = std::find(li.begin(), li.end(), 3);

    if (it != li.end())
        li.insert(it, 42);

    for (auto i : li)
        std::cout << i << ' ';

    std::cout << '\n';


    // Create a vector of integers
    std::vector<int> vect{ 7, -3, 6, 2, -5, 0, 4 };

    // Reverse the order of the elements in li.
    std::reverse(vect.begin(), vect.end());

    for (auto i : vect)
        std::cout << i << ' ';

    std::cout << '\n';

    // Sort the elements in vect again.
    std::sort (vect.begin(), vect.end());

    for (auto i : vect)
        std::cout << i << ' ';

    std::cout << '\n';

    // Shuffle the elements in vect.
    std::random_shuffle(vect.begin(), vect.end());

    for (auto i : vect)
        std::cout << i << ' ';

    std::cout << '\n';
    return 0;
}