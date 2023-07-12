#include <iostream>

class Base
{
private: // our member is now private
    int m_id {};

public:
    Base(int id=0)
        : m_id{ id }
    {
    }

    int getId() const { return m_id; }
};

class Derived: public Base
{
private: // our member is now private
    double m_cost;

public:
    Derived(double cost=0.0, int id=0)
        : Base{ id } // Call Base(int) constructor with value id!
        , m_cost{ cost }
    {
    }

    double getCost() const { return m_cost; }
};

int main()
{
    Base base{ 5 }; // use Base(int) constructor

    Derived derived{ 1.3 }; // use Derived(double) constructor

    Derived derived2{ 1.3, 5 }; // use Derived(double, int) constructor, also calls Base(int) constructor with value 5

    return 0;
}