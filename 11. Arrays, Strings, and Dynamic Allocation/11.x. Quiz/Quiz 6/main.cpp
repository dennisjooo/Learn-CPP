#include "card_logic.h"
#include <iostream>

char getPlayerChoice()
{
    std::cout << "(h) to hit, or (s) to stand: ";
    char choice{};
    do
    {
        std::cin >> choice;
    } while (choice != 'h' && choice != 's');

    return choice;
}

bool playBlackjack(const Deck& deck)
{
    // Set up the initial game state
    const Card* cardPtr{ &deck[0] };

    int playerTotal{ getCardValue(*cardPtr++) }; // Player draws first card
    int dealerTotal{ getCardValue(*cardPtr++) }; // Dealer draws first card

    // Player's turn
    while (true)
    {
        std::cout << "You have: " << playerTotal << '\n';
        std::cout << "Dealer has: " << dealerTotal << '\n';

        if (playerTotal > 21)
        {
            return false;
        }
        else
        {
            char choice{ getPlayerChoice() };
            if (choice == 's')
            {
                break;
            }

            playerTotal += getCardValue(*cardPtr++);
        }
    }

    // If player hasn't busted, dealer draws cards until their total is 17 or more
    while (dealerTotal < 17)
    {
        dealerTotal += getCardValue(*cardPtr++);
        std::cout << "The dealer now has: " << dealerTotal << '\n';
    }

    // If dealer busted, player wins
    if (dealerTotal > 21)
    {
        return true;
    }

    return (playerTotal > dealerTotal);
}

int main()
{   
    char choice{ 'y' };

    do
    {
        auto deck{ createDeck() };
        shuffleDeck(deck);

        if (playBlackjack(deck))
        {
            std::cout << "You win!\n";
        }
        else
        {
            std::cout << "You lose!\n";
        }

        std::cout << "Play again? (y/n): ";
        std::cin >> choice;
        
    } while (choice != 'n');
    
    

    return 0;
}