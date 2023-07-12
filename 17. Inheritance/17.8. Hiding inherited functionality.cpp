#include <iostream>

class Base
{
private:
    int m_value {};

public:
    int m_publicValue {};
    Base(int value)
        : m_value { value }
        , m_publicValue { value }
    {
    }

    int getValue() const { return m_value; }
    
protected:
    void printValue() const { std::cout << m_value; }
};

class Derived: public Base
{
    private: using Base::m_publicValue; // note: no parenthesis here, m_publicValue is public in Base, so it's supposed to be public here, but we're hiding it using private access

    public:
        Derived(int value)
            : Base { value }
        {
        }

        // Base::printValue was inherited as protected, so the public has no access
        // But we're changing it to public via a using declaration
        using Base::printValue; // note: no parenthesis here

        int getValue() const = delete; // mark this function as inaccessible
};

int main()
{
    Derived derived { 7 };

    // printValue is public in Derived, so this is okay
    derived.printValue(); // prints 7
    return 0;
}