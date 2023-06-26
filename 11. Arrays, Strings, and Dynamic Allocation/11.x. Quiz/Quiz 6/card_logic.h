#ifndef CARD_LOGIC_H
#define CARD_LOGIC_H

#include <iostream>
#include <array>
#include <algorithm> // for std::shuffle
#include <ctime> // for std::time
#include <random> // for std::mt19937

enum class CardSuit
{
    club,
    diamond,
    heart,
    spade,

    max_suits
};

enum class CardRank
{
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    rank_ace,

    max_ranks
};
struct Card
{
    CardRank rank{};
    CardSuit suit{};
};

using Deck = std::array<Card, 52>;
using Index = Deck::size_type;


void printCard(const Card& card)
{
    switch (card.rank)
    {
        case CardRank::rank_2:      std::cout << '2';   break;
        case CardRank::rank_3:      std::cout << '3';   break;
        case CardRank::rank_4:      std::cout << '4';   break;
        case CardRank::rank_5:      std::cout << '5';   break;
        case CardRank::rank_6:      std::cout << '6';   break;
        case CardRank::rank_7:      std::cout << '7';   break;
        case CardRank::rank_8:      std::cout << '8';   break;
        case CardRank::rank_9:      std::cout << '9';   break;
        case CardRank::rank_10:     std::cout << 'T';   break;
        case CardRank::rank_jack:   std::cout << 'J';   break;
        case CardRank::rank_queen:  std::cout << 'Q';   break;
        case CardRank::rank_king:   std::cout << 'K';   break;
        case CardRank::rank_ace:    std::cout << 'A';   break;
        default:
            std::cout << '?';
            break;
    }

    switch (card.suit)
    {
        case CardSuit::club:       std::cout << 'C';   break;
        case CardSuit::diamond:    std::cout << 'D';   break;
        case CardSuit::heart:      std::cout << 'H';   break;
        case CardSuit::spade:      std::cout << 'S';   break;
        default:
            std::cout << '?';
            break;
    }
};

Deck createDeck()
{
    Deck deck{};

    Index card{ 0 };
    
    auto suits{ static_cast<Index>(CardSuit::max_suits) };
    auto ranks{ static_cast<Index>(CardRank::max_ranks) };

    for (Index suit{ 0 }; suit < suits; ++suit)
    {
        for (Index rank{ 0 }; rank < ranks; ++rank)
        {
            deck[card].suit = static_cast<CardSuit>(suit);
            deck[card].rank = static_cast<CardRank>(rank);
            ++card;
        }
    }

    return deck;
};

void printDeck(const Deck& deck)
{
    for (const auto& card : deck)
    {
        printCard(card);
        std::cout << ' ';
    }

    std::cout << '\n';
};

void shuffleDeck(Deck& deck)
{
  // mt is static so it only gets seeded once.
  static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

  std::shuffle(deck.begin(), deck.end(), mt);
};

int getCardValue(const Card& card)
{
    if (card.rank <= CardRank::rank_10)
    {
        return (static_cast<int>(card.rank) + 2);
    }

    switch (card.rank)
    {
        case CardRank::rank_jack:
        case CardRank::rank_queen:
        case CardRank::rank_king:
            return 10;
        case CardRank::rank_ace:
            return 11;
        default:
            return 0;
    }
};


#endif // CARD_LOGIC_H