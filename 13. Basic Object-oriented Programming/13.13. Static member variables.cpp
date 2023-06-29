#include <iostream>

class Something
{
public:
    static int s_value; // Shared between all objects of the class

    // Const, constexpr, and inline static member variables can be initialized directly inside the class
    static const int s_value2{ 1 }; // This is a const static member variable, so it needs to be initialized here
    static constexpr int s_value3{ 1 }; // This is a const static member variable, so it needs to be initialized here
    static inline int s_value4{ 1 }; // This is a const static member variable, so it needs to be initialized here
};

int Something::s_value{ 1 }; // We need to define the static non-const member variable outside the class as it's not part of the object (you put this in .cpp file, not in .h file)


class IdGenerator
{
private:
    static inline int s_idGenerator { 1 }; // C++17
//  static int s_idGenerator;              // Use this instead for C++14 or older
    int m_id { };

public:
    IdGenerator()
    : m_id { s_idGenerator++ } // grab the next value from the id generator
    {}

    int getID() const { return m_id; }
};


int main()
{
    Something first;
    Something second;

    first.s_value = 2;

    std::cout << first.s_value << '\n';
    std::cout << second.s_value << '\n';


    // The static is actually not part of the object, it's part of the class, so we can access it without an object (preferred)
    std::cout << Something::s_value << '\n';



    // ID Generator example
    IdGenerator generator;
    IdGenerator generator2;
    IdGenerator generator3;

    std::cout << generator.getID() << '\n';  // prints 1
    std::cout << generator2.getID() << '\n'; // prints 2
    std::cout << generator3.getID() << '\n'; // prints 3
    return 0;
}