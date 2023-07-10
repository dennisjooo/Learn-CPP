#include <iostream>
#include <string>
#include <vector>
#include <string>

class Teacher
{
    private:
        std::string m_name{};

    public:
        Teacher(const std::string& name)
            : m_name{ name }
        {
        }

        const std::string& getName() const { return m_name; }
};

class Department
{
    private:
        const Teacher& m_teacher; // This dept holds only one teacher for simplicity, but it could hold many teachers

    public:
        Department(const Teacher& teacher)
            : m_teacher{ teacher }
        {
        }
};

class Department_2
{
    private:
        std::vector<std::reference_wrapper<const Teacher>> m_teachers{};

    public:
        // Pass by regular reference. The user of the Department class shouldn't care
        // about how it's implemented.
        void add(const Teacher& teacher)
        {
            m_teachers.push_back(teacher);
        }

        friend std::ostream& operator<<(std::ostream& out, const Department_2& department)
        {
            out << "Department: ";

            for (const auto& teacher : department.m_teachers)
            {
            out << teacher.get().getName() << ' ';
            }

            out << '\n';

    return out;
    }
};

int main()
{
    // Create a teacher outside the scope of the Department
    Teacher bob{ "Bob" }; // create a teacher

    {
        // Create a department and use the constructor parameter to pass
        // the teacher to it.
        Department department{ bob };

    } // department goes out of scope here and is destroyed

    // bob still exists here, but the department doesn't

    std::cout << bob.getName() << " still exists!\n";


    // std::reference_wrapper
    // std::reference_wrapper is a class template that wraps a reference in a copyable, assignable object.
    std::string tom{ "Tom" };
    std::string berta{ "Berta" };

    std::vector<std::reference_wrapper<std::string>> names{ tom, berta }; // these strings are stored by reference, not value

    std::string jim{ "Jim" };

    names.push_back(jim);

    for (auto name : names)
    {
        // Use the get() member function to get the referenced string.
        name.get() += " Beam";
    }

    std::cout << jim << '\n'; // Jim Beam


    // Modified Department class with std::reference_wrapper
    // Create a teacher outside the scope of the Department
    Teacher t1{ "Bob" };
    Teacher t2{ "Frank" };
    Teacher t3{ "Beth" };

    {
        // Create a department and add some Teachers to it
        Department_2 department{}; // create an empty Department

        department.add(t1);
        department.add(t2);
        department.add(t3);

        std::cout << department;

    } // department goes out of scope here and is destroyed

    std::cout << t1.getName() << " still exists!\n";
    std::cout << t2.getName() << " still exists!\n";
    std::cout << t3.getName() << " still exists!\n";
    
    return 0;
}