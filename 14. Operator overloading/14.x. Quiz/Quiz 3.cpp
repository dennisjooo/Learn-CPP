#include <iostream>
#include <cassert> // for assert

class IntArray
{
    private:
        int m_length{};
        int* m_data{};
    public:
        explicit IntArray(int length) : m_length{ length }
        {   
            assert(length > 0 && "IntArray length should be a positive integer");
            m_data = new int[length]{};
        }

        IntArray(const IntArray& arr) : m_length{ arr.m_length }
        {
            m_data = new int[m_length];

            for (int i{ 0 }; i < arr.m_length; ++i)
                m_data[i] = arr.m_data[i];
        }

        ~IntArray()
        {
            delete[] m_data;
        }

        friend std::ostream& operator<<(std::ostream& out, const IntArray& arr);

        int& operator[](int index)
        {
            return m_data[index];
        }


        IntArray& operator= (const IntArray& arr)
        {
            if (&arr == this)
                return *this;

            delete[] m_data;

            m_length = arr.m_length;

            m_data = new int[m_length];

            for (int i{ 0 }; i < arr.m_length; ++i)
                m_data[i] = arr.m_data[i];

            return *this;
        }
};

std::ostream& operator<<(std::ostream& out, const IntArray& arr)
{
    for (int i{ 0 }; i < arr.m_length; ++i)
        out << arr.m_data[i] << ' ';

    return out;
}

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{ fillArray() };

	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	a[4] = 7;

	std::cout << b << '\n';

	return 0;
}