#include <iostream>

class Something
{
public:
    int m_value {};

    Something(): m_value{0} { }

    void setValue(int value) { m_value = value; }
    int getValue() const { return m_value ; } // Need to add const here to make it a const member function

    int getValue(){ return m_value;} // This is not a const member function
};

int main()
{
    const Something something{}; // calls default constructor

    // something.m_value = 5; // compiler error: violates const
    // something.setValue(5); // compiler error: violates const

    std::cout << something.getValue() << '\n'; // okay: does not violate const


    Something something2{};
    something2.setValue(5); // okay: does not violate const
    std::cout << something2.getValue() << '\n'; // okay: does not violate const, uses non-const version of getValue()

    return 0;
}