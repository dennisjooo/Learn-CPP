#include <iostream>
#include <string>
#include <string_view>
#include <memory> // for std::unique_ptr

class Person
{
    private:
        std::string m_name;
        int m_age;
    public:
        Person(std::string_view name, int age)
            : m_name{ name }, m_age{ age }
        {
            if (age < 0 || age > 150)
                throw std::invalid_argument{ "Invalid age" };
        }

        std::string_view getName() const { return m_name; }
        int getAge() const { return m_age; }
};

int main()
{
    // Danger 1: Exceptions doesn't clean up after themselves (memory leak)
    Person* personPtr{ nullptr };

    try
    {
        personPtr = new Person{ "John", 25 };
    }
    catch (...)
    {
        std::cerr << "An error occurred\n";
    }

    delete personPtr; // Needs to be outside the try block


    // Can also use unique_ptr to avoid memory leak
    try{
        std::unique_ptr<Person> personPtr{ new Person{ "John", 25 } };
    }
    catch (...)
    {
        std::cerr << "An error occurred\n";
    }


    // Danger 2: Exceptions can be thrown from destructors (do not do this)
    // Danger 3: Performance (exceptions are slow especially if it's thrown due to the stack unwinding)
}