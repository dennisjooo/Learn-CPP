#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
    int m_id{};
    std::string m_name{};

public:
    Employee(int id=0, std::string_view name=""):
        m_id{ id }, m_name{ name }
    {
        std::cout << "Employee " << m_name << " created.\n";
    }

    // Use a delegating constructor to minimize redundant code
    Employee(std::string_view name) : Employee{ 0, name }
    { }
};

class Foo
{
private:
    int m_a{ 5 };
    int m_b{ 6 };


public:
    Foo()
    {
    }

    Foo(int a, int b)
        : m_a{ a }, m_b{ b }
    {
    }

    void print()
    {
        std::cout << m_a << ' ' << m_b << '\n';
    }

    void reset()
    {
        // consider this a bit of magic for now
        *this = Foo{}; // create new Foo object, then use assignment to overwrite our implicit object
    }
};

int main()
{   
    // Delegating constructors
    Employee alex{ "Alex" };
    Employee joe{ 1, "Joe" };


    // Resetting objects
    Foo foo{ 1, 2 };
    foo.print();

    foo.reset();
    foo.print();
    return 0;
}