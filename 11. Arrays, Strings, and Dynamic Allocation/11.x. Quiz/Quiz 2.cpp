#include <iostream>
#include <vector>
#include <algorithm>

struct Student
{
    std::string name{};
    int grade{};
};

Student getStudent()
{
    Student temp{};
    std::cout << "Enter name: ";
    std::cin >> temp.name;
    std::cout << "Enter grade: ";
    std::cin >> temp.grade;
    return temp;
}

void printStudent(const Student& student)
{
    std::cout << student.name << " got a grade of " << student.grade << '\n';
}

bool compareStudent(const Student& a, const Student& b)
{
    return (a.grade > b.grade);
}

int main()
{
    std::cout << "How many students do you want to enter? ";
    int numStudents{};
    std::cin >> numStudents;

    std::vector<Student> students{};
    students.reserve(static_cast<size_t>(numStudents));

    for (int i{ 0 }; i < numStudents; ++i)
    {
        std::cout << "Enter data for student #" << i + 1 << '\n';
        students.push_back(getStudent());
    }

    // Sort students by grade
    std::sort(students.begin(), students.end(), compareStudent);

    // Print students
    for (const auto& student : students)
    {
        printStudent(student);
    }


}