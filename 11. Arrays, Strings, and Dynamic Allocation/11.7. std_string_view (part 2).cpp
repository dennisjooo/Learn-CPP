#include <cstring>
#include <iostream>
#include <string>
#include <string_view>

int main()
{
    std::string_view text{ "hello" }; // view the text "hello", which is stored in the binary
    std::string_view str{ text }; // view of the same "hello"
    std::string_view more{ str }; // view of the same "hello"

    std::cout << text << ' ' << str << ' ' << more << '\n';

    
    // String View Methods
    std::string_view str{ "Trains are fast!" };

    std::cout << str.length() << '\n'; // 16
    std::cout << str.substr(0, str.find(' ')) << '\n'; // Trains
    std::cout << (str == "Trains are fast!") << '\n'; // 1

    // Since C++20
    std::cout << str.starts_with("Boats") << '\n'; // 0
    std::cout << str.ends_with("fast!") << '\n'; // 1

    std::cout << str << '\n'; // Trains are fast!

    // Ignore the first character.
    str.remove_prefix(1);

    std::cout << str << '\n';

    // Ignore the last 2 characters.
    str.remove_suffix(2);

    std::cout << str << '\n';
    

    // Non null-terminated C-Style Strings to String View
    char vowels[]{ 'a', 'e', 'i', 'o', 'u' };

    // vowels isn't null-terminated. We need to pass the length manually.
    // Because vowels is an array, we can use std::size to get its length.
    std::string_view str{ vowels, std::size(vowels) };

    std::cout << str << '\n'; // This is safe. std::cout knows how to print std::string_view.


    // String view to C-Style String (avoid because expensive) 
    std::string_view sv{ "balloon" };

    sv.remove_suffix(3);

    // Create a std::string from the std::string_view
    std::string str2{ sv };

    // Get the null-terminated C-style string.
    auto szNullTerminated{ str2.c_str() };

    // Pass the null-terminated string to the function that we want to use.
    std::cout << str2 << " has " << std::strlen(szNullTerminated) << " letter(s)\n";


    // using the Data Method (use if you need to pass a null-terminated string or the string-view hasn't been modified)
    std::string_view str{ "balloon" };

    std::cout << str << '\n';

    // We use std::strlen because it's simple, this could be any other function
    // that needs a null-terminated string.
    // It's okay to use data() because we haven't modified the view, and the
    // string is null-terminated.
    std::cout << std::strlen(str.data()) << '\n';
    return 0;
}