#include <iostream>
#include <stdexcept>

class Fraction
{
    private:
        int m_numerator{ 0 };
        int m_denominator{ 1 };

    public:
        Fraction(int numerator = 0, int denominator = 1) :
            m_numerator{ numerator }, m_denominator{ denominator }
        {
            if (m_denominator == 0)
                throw std::runtime_error("Invalid denominator");
        }

        friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
}


Fraction getFraction()
{
    std::cout << "Enter a numerator: ";
    int numerator{};
    std::cin >> numerator;

    std::cout << "Enter a denominator: ";
    int denominator{};
    std::cin >> denominator;

    Fraction fraction{ numerator, denominator };

    return fraction;
}

int main()
{
    try
    {
        Fraction my_fraction { getFraction() };
        std::cout << "Your fraction is: " << my_fraction << '\n';
    }
    catch (std::exception& exception)
    {
        std::cerr << "Exception: " << exception.what() << '\n';
    }
    return 0;
}