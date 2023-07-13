#include <iostream>

class Base
{
public:
    virtual ~Base() // note: virtual
    {
        std::cout << "Calling ~Base()\n";
    }

    virtual std::string_view getName() const { return "Base"; }
};

class Derived: public Base
{
private:
    int* m_array {};
    int m_length {};

public:

    int getLength() const { return m_length; }

    Derived(int length)
      : m_array{ new int[length] }, m_length{ length }
    {
    }

    Derived(const Derived& cpy)
      : m_array{ new int[cpy.getLength()] }
    {
    }

    virtual ~Derived() // note: virtual
    {
        std::cout << "Calling ~Derived()\n";
        delete[] m_array;
    }

    Derived& operator=(const Derived& cpy)
    {
        std::cout << "Calling operator=()\n";
        if (this == &cpy)
            return *this;

        delete[] m_array;

        m_length = cpy.getLength();
        m_array = new int[m_length];

        return *this;
    }

    virtual std::string_view getName() const { return "Derived"; }
};

int main()
{

    Derived* derived { new Derived(5) };
    Base* base { derived };


    // Ignoring virtualization
    // Calls Base::getName() instead of the virtualized Derived::getName()
    std::cout << base->Base::getName() << '\n';

    delete base;

    return 0;
}