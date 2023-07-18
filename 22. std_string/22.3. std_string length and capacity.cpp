#include <iostream>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

int main()
{   
    // Length and empty
    std::string ss { "012345678" };
    std::cout << ss.length() << '\n';

    std::string string1 { "Not Empty" };
    std::cout << (string1.empty() ? "true" : "false") << '\n';
    std::string string2; // empty
    std::cout << (string2.empty() ? "true" : "false")  << '\n';


    // Length and capacity
    std::string s { "01234567" };
    std::cout << "Length: " << s.length() << '\n';
    std::cout << "Capacity: " << s.capacity() << '\n';

    s.reserve(200);
    std::cout << "Length: " << s.length() << '\n';
    std::cout << "Capacity: " << s.capacity() << '\n';

    s.reserve();
    std::cout << "Length: " << s.length() << '\n';
    std::cout << "Capacity: " << s.capacity() << '\n';


    // Random string generation
    std::srand(std::time(nullptr)); // seed random number generator

    std::string s2{}; // length 0
    s2.reserve(64); // reserve 64 characters

    // Fill string up with random lower case characters
    for (int count{ 0 }; count < 64; ++count)
        s2 += 'a' + std::rand() % 26;

    std::cout << s2;
}