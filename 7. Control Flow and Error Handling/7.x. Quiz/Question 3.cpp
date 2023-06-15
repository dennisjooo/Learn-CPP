#include <iostream>
#include <random>

int getRandomNumber(int min, int max);
bool checkNumber(int number, int userGuess);
int getUserGuess(int min, int max, int count);

int main()
{
    std::cout << "Let's play a game.  I'm thinking of a number.  You have 7 tries to guess what it is.\n";

    int number { getRandomNumber(1, 100) };

    for (int count = 1; count <= 7; ++count)
    {
        
        int userGuess { getUserGuess(1, 100, count) };

        if (checkNumber(number, userGuess))
            break;

        if (count == 7)
            std::cout << "Sorry, you lose.  The correct number was " << number << ".\n";
    }
}

int getUserGuess(int min, int max, int count)
{
    
    
    while (true)
    {   
        std::cout << "Guess #" << count << ": ";
        int userGuess;
        std::cin >> userGuess;

        if (std::cin.fail()) // did the extraction fail?
		{
			// yep, so let's handle the failure
			std::cin.clear(); // put us back in 'normal' operation mode
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove the bad input
			continue; // and try again
		}

        if (userGuess < min || userGuess > max)
        {
            std::cout << "Your guess must be between " << min << " and " << max << ".\n";
            continue;
        }

        // We may have gotten a partial extraction (e.g. user entered '43x')
		// We'll remove any extraneous input before we proceed
		// so the next extraction doesn't fail
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
        return userGuess;
    }
}

int getRandomNumber(int min, int max)
{
      
    std::random_device rd; // obtain a random number from hardware
    
    std::seed_seq seed { rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() }; // seed the generator

    std::mt19937 mt(seed); // standard mersenne_twister_engine seeded with rd()

    return std::uniform_int_distribution{ min, max }(mt);

}

bool checkNumber(int number, int userGuess)
{
    if (userGuess == number)
    {
        std::cout << "Correct! You win!\n";
        return true;
    }
    else if (userGuess < number)
    {
        std::cout << "Your guess is too low.\n";
        return false;
    }
    else
    {
        std::cout << "Your guess is too high.\n";
        return false;
    }
}