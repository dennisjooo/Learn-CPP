#include <iostream>
#include <string_view>
#include <string>
#include <array>
#include "Random.h"
#include <sstream> // for std::stringstream

class Creature
{
    protected:
        std::string m_name;
        char m_symbol;
        int m_health;
        int m_damage;
        int m_gold;
    public:
        Creature(std::string_view name, char symbol, int health, int damage, int gold)
            : m_name{ name }, m_symbol{ symbol }, m_health{ health }, m_damage{ damage }, m_gold{ gold }
        {
        }

        std::string_view getName() const { return m_name; }

        char getSymbol() const { return m_symbol; }

        int getHealth() const { return m_health; }

        int getDamage() const { return m_damage; }

        int getGold() const { return m_gold; }

        void reduceHealth(int health) { m_health -= health; }

        bool isDead() const { return m_health <= 0; }

        void addGold(int gold) { m_gold += gold; }

        void increaseHealth(int health) { m_health += health; }

        void increaseDamage(int damage) { ++m_damage; }
};

class Player : public Creature
{
    private:
        int m_level{ 1 };
    public:
        Player(std::string_view name)
            : Creature{ name, '@', 10, 1, 0 }
        {
        }

        int getLevel() const { return m_level; }

        void levelUp() { ++m_level; ++m_damage; }

        bool hasWon() const { return m_level >= 20; }
    
};

class Monster : public Creature
{
    public:
        enum Type
        {
            DRAGON,
            ORC,
            SLIME,
            MAX_TYPES
        };

    private:
        static const Creature& getDefaultCreature(Type type)
        {
            static const std::array<Creature, static_cast<std::size_t>(Type::MAX_TYPES)> monsterData{
            {   { "dragon", 'D', 20, 4, 100 },
                { "orc", 'o', 4, 2, 25 },
                { "slime", 's', 1, 1, 10 } }
            };

            return monsterData.at(static_cast<std::size_t>(type));
        }

    public:
        Monster(Type type)
            : Creature{ getDefaultCreature(type) }
        {
        }

        static Monster getRandomMonster()
        {
            int num{ Random::get(0, static_cast<int>(Type::MAX_TYPES) - 1) };
            return Monster{ static_cast<Type>(num) };
        }
};

void attackMonster(Player& player, Monster& monster)
{
    if (player.isDead())
        return;

    std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.\n";

    monster.reduceHealth(player.getDamage());

    if (monster.isDead())
    {
        std::cout << "You killed the " << monster.getName() << ".\n";
        player.levelUp();
        std::cout << "You are now level " << player.getLevel() << ".\n";
        std::cout << "You found " << monster.getGold() << " gold.\n";
        player.addGold(monster.getGold());
    }
}

void attackPlayer(Monster& monster, Player& player)
{
    if (monster.isDead())
        return;

    std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage.\n";

    player.reduceHealth(monster.getDamage());

    if (player.isDead())
    {
        std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
        std::cout << "Too bad you can't take it with you!\n";
    }
}

void fightMonster(Player& player)
{
    Monster monster{ Monster::getRandomMonster() };
    std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";

    while (!monster.isDead() && !player.isDead())
    {
        std::cout << "(R)un or (F)ight: ";
        char input{};
        std::cin >> input;

        if (input == 'R' || input == 'r')
        {
            if (Random::get(0, 1))
            {
                std::cout << "You successfully fled.\n";
                return;
            }
            else
            {
                std::cout << "You failed to flee.\n";
                attackPlayer(monster, player);
                continue;
            }
        }

        if (input == 'F' || input == 'f')
        {
            attackMonster(player, monster);
            attackPlayer(monster, player);
            continue;
        }
    }
}

int main()
{
    std::cout << "Enter your name: ";
    std::string playerName{};
    std::cin >> playerName;

    Player player{ playerName };

    std::cout << "Welcome, " << player.getName() << '\n';

    while (!player.isDead() && !player.hasWon())
        fightMonster(player);

    if (player.isDead())
        std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
    else
        std::cout << "You won the game with " << player.getGold() << " gold!\n";

    return 0;
}

