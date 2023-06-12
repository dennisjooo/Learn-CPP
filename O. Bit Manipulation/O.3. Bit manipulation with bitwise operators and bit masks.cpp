#include <cstdint>
#include <iostream>
#include <bitset>

int main()
{
	[[maybe_unused]] constexpr std::uint8_t mask0{ 0b0000'0001 }; // represents bit 0
	[[maybe_unused]] constexpr std::uint8_t mask1{ 0b0000'0010 }; // represents bit 1
	[[maybe_unused]] constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit 2
	[[maybe_unused]] constexpr std::uint8_t mask3{ 0b0000'1000 }; // represents bit 3
	[[maybe_unused]] constexpr std::uint8_t mask4{ 0b0001'0000 }; // represents bit 4
	[[maybe_unused]] constexpr std::uint8_t mask5{ 0b0010'0000 }; // represents bit 5
	[[maybe_unused]] constexpr std::uint8_t mask6{ 0b0100'0000 }; // represents bit 6
	[[maybe_unused]] constexpr std::uint8_t mask7{ 0b1000'0000 }; // represents bit 7

    
    // Testing a bit
	std::uint8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags

	std::cout << "bit 0 is " << ((flags & mask0) ? "on\n" : "off\n");
	std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");


    //Setting a bit
    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

    flags |= mask1; // turn on bit 1

    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

    flags |= (mask4 | mask5); // turn bits 4 and 5 on at the same time


    // Resetting a bit
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

    flags &= static_cast<std::uint8_t>(~mask2);

    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");


    // Flipping a bit

    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    flags ^= mask2; // flip bit 2
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    flags ^= mask2; // flip bit 2
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

    flags ^= (mask4 | mask5); // flip bits 4 and 5 at the same time

    // Clearer definitions of masks
    // Define a bunch of physical/emotional states
	[[maybe_unused]] constexpr std::bitset<8> isHungry{	0b0000'0001 };
	[[maybe_unused]] constexpr std::bitset<8> isSad{	0b0000'0010 };
	[[maybe_unused]] constexpr std::bitset<8> isMad{	0b0000'0100 };
	[[maybe_unused]] constexpr std::bitset<8> isHappy{	0b0000'1000 };
	[[maybe_unused]] constexpr std::bitset<8> isLaughing{	0b0001'0000 };
	[[maybe_unused]] constexpr std::bitset<8> isAsleep{	0b0010'0000 };
	[[maybe_unused]] constexpr std::bitset<8> isDead{	0b0100'0000 };
	[[maybe_unused]] constexpr std::bitset<8> isCrying{	0b1000'0000 };


	std::bitset<8> me{}; // all flags/options turned off to start
	me |= (isHappy | isLaughing); // I am happy and laughing
	me &= ~isLaughing; // I am no longer laughing

	// Query a few states (we use the any() function to see if any bits remain set)
	std::cout << "I am happy? " << (me & isHappy).any() << '\n';
	std::cout << "I am laughing? " << (me & isLaughing).any() << '\n';


    // Quiz
    [[maybe_unused]] constexpr std::uint8_t option_viewed{ 0x01 };
    [[maybe_unused]] constexpr std::uint8_t option_edited{ 0x02 };
    [[maybe_unused]] constexpr std::uint8_t option_favorited{ 0x04 };
    [[maybe_unused]] constexpr std::uint8_t option_shared{ 0x08 };
    [[maybe_unused]] constexpr std::uint8_t option_deleted{ 0x10 };

    std::uint8_t myArticleFlags{ option_favorited };

    myArticleFlags |= option_viewed;

    std::cout << std::bitset<8>{ myArticleFlags } << '\n';

    std::cout << "Is the article deleted? " << ((myArticleFlags & option_deleted) ? "yes\n" : "no\n");

    std::cout << "Is the article favorited? " << ((myArticleFlags & option_favorited) ? "yes\n" : "no\n");
	return 0;
}