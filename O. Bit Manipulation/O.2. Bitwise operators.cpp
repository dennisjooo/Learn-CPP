#include <bitset>
#include <iostream>

std::bitset<4> rotl(std::bitset<4> bits)
{
    // rotate left
    bool highbit { bits.test(3) }; // save the high bit before it gets shifted out
    bits <<= 1; // shift all the bits left by 1
    if (highbit) {
        bits.set(0); // set the low bit if the high bit was set
    }
    return bits; // or simply: return (bits << 1) | (bits >> 3);
}


int main()
{
    std::bitset<4> x { 0b1100 };

    // Bitwise shift
    std::cout << x << '\n';
    std::cout << (x >> 1) << '\n'; // shift right by 1, yielding 0110
    std::cout << (x << 1) << '\n'; // shift left by 1, yielding 1000

    std::cout << x << 1 << '\n'; // print value of x (0110), then 1
	std::cout << (x << 1) << '\n'; // print x left shifted by 1 (1100)

    
    // Bitwise NOT
    std::cout << ~std::bitset<4>{ 0b0100 } << ' ' << ~std::bitset<8>{ 0b0100 } << '\n'; // will yield different output due to different size of bitset

    
    // Bitwise OR
    std::cout << (std::bitset<4>{ 0b0101 } | std::bitset<4>{ 0b0110 }) << '\n'; // performs OR operation on each bit pair(s)
    std::cout << (std::bitset<4>{ 0b0111 } | std::bitset<4>{ 0b0011 } | std::bitset<4>{ 0b0001 }) << '\n';


    // Bitwise AND
    std::cout << (std::bitset<4>{ 0b0101 } & std::bitset<4>{ 0b0110 }) << '\n';
    std::cout << (std::bitset<4>{ 0b0001 } & std::bitset<4>{ 0b0011 } & std::bitset<4>{ 0b0111 }) << '\n';


    // Bitwise assignment (works with <<=, >>=, |=, &=, ^=)
    std::bitset<4> bits { 0b0100 };
    bits >>= 1;
    std::cout << bits << '\n';


    // Bitwise rotation
    std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1) << '\n';

	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';

    return 0;
}