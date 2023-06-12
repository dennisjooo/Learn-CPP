#include <iostream>
#include <bitset>

// Prototypes declarations
int binaryToDecimal(std::bitset<8> n);
int binaryToSignedDecimal(std::bitset<8> n);
std::bitset<8> invBits(std::bitset<8> n);
std::bitset<8> addOneBits(std::bitset<8> n);
std::bitset<8> decimalToBinary(int n);
std::bitset<8> signedDecimalToBinary(int n);

int main()
{   
    // Test case instantiations
    std::bitset<8> test { 0b1010'0010 };

    // Test case outputs
    std::cout << "Original bitset: " << test << '\n';
    std::cout << binaryToDecimal(test) << '\n';
    std::cout << binaryToSignedDecimal(test) << '\n';

    std::cout << decimalToBinary(162) << '\n';
    std::cout << signedDecimalToBinary(-94) << '\n';
}

// Convert a binary number to decimal by adding binary values to a result variable
int binaryToDecimal(std::bitset<8> n)
{
    int result { 0 };
    for (std::size_t i { 0 }; i < n.size(); ++i)
    {
        if (n.test(i))
        {
            result += (1 << i);
        }
    }
    return result;
}

// Consider the sign bit and convert a binary number to decimal by adding binary values to a result variable
int binaryToSignedDecimal(std::bitset<8> n)
{
    int result { 0 };
    if (n.test(7))
    {
        n = invBits(n);
        n = addOneBits(n);
        result = -binaryToDecimal(n);
    }
    else
    {
        result = binaryToDecimal(n);
    }
    return result;


}

// Convert a decimal number to binary by dividing by 2 and adding the remainder to a result variable
std::bitset<8> decimalToBinary(int n)
{
    std::bitset<8> result {};
    std::size_t i { 0 };
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            result.set(i);
        }
        n /= 2;
        ++i;
    }
    return result;
}

// Consider the sign bit and convert a decimal number to binary by dividing by 2 and adding the remainder to a result variable
std::bitset<8> signedDecimalToBinary(int n)
{
    std::bitset<8> result {};
    if (n < 0)
    {
        result = decimalToBinary(-n);
        result = invBits(result);
        result = addOneBits(result);
    }
    else
    {
        result |= decimalToBinary(n);
    }
    return result;
}


// Invert all bits in a bitset
std::bitset<8> invBits(std::bitset<8> n)
{
    std::bitset<8> result {};
    for (std::size_t i { 0 }; i < n.size(); ++i)
    {
        if (!n.test(i))
        {
            result.set(i);
        }
    }
    return result;
}

// Add one to the bitset
std::bitset<8> addOneBits(std::bitset<8> n)
{   
    for (std::size_t i { 0 }; i < n.size(); ++i)
    {
        if (!n.test(i))
        {
            n.set(i);
            break;
        }
        else
        {
            n.reset(i);
        }
    }

    return n;
}