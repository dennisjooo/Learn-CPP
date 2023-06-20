#include <string>

const std::string& getConstRef(); // some function that returns a const reference

std::string* getPtr(); // some function that returns a pointer

int main()
{   
    // References
    auto ref1{ getConstRef() };        // std::string (top-level const and reference dropped)
    const auto ref2{ getConstRef() };  // const std::string (const reapplied, reference dropped)

    auto& ref3{ getConstRef() };       // const std::string& (reference reapplied, low-level const not dropped)
    const auto& ref4{ getConstRef() }; // const std::string& (reference and const reapplied)


    // Pointers
    auto ptr1{ getPtr() }; // std::string* (pointer is not dropped)
    auto* ptr2{ getPtr() }; // std::string*
    return 0;
}


const std::string& getConstRef()
{
    static std::string s{ "Hello, world!" };
    return s;
}

std::string* getPtr()
{
    static std::string s{ "Hello, world!" };
    return &s;
}