// Define our different monster types as an enum
#include <iostream>
#include <string>
#include <string_view>

enum class MonsterType
{
	ogre,
	dragon,
	orc,
	giant_spider,
	slime,
};

// Our monster struct represents a single monster
struct Monster
{
	MonsterType type{};
	std::string name{};
	int health{};
};

// Return the name of the monster's type as a string
// Since this could be used elsewhere, it's better to make this its own function
constexpr std::string_view getMonsterTypeString(MonsterType type)
{
	switch (type)
	{
	case MonsterType::ogre:          return "Ogre";
	case MonsterType::dragon:        return "Dragon";
	case MonsterType::orc:           return "Orc";
	case MonsterType::giant_spider:  return "Giant Spider";
	case MonsterType::slime:         return "Slime";
	}

	return "Unknown";
}

// Print our monster's stats
void printMonster(const Monster& monster)
{
	std::cout << "This " << getMonsterTypeString(monster.type) <<
		" is named " << monster.name <<
		" and has " << monster.health << " health.\n";
}

int main()
{
	Monster ogre{ MonsterType::ogre, "Torg", 145 };
	Monster slime{ MonsterType::slime, "Blurp", 23 };

	printMonster(ogre);
	printMonster(slime);

	return 0;
}