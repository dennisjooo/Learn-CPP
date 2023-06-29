#include <string>
#include <iostream>
#include "Random.h"
#include <array>

class Monster
{   
    public:
        enum Type
        {
            dragon,
            goblin,
            ogre,
            orc,
            skeleton,
            troll,
            vampire,
            zombie,
            max_monster_types
        };

    private:
        Type m_type{};
        std::string m_name{};
        std::string m_roar{};
        int m_hitPoints{};

    public:
        Monster(Type type, std::string name, std::string roar, int hitPoints)
            : m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hitPoints}
        {
        }

        std::string_view getTypeString() const
	{
		switch (m_type)
		{
		case Type::dragon: return "dragon";
		case Type::goblin: return "goblin";
		case Type::ogre: return "ogre";
		case Type::orc: return "orc";
		case Type::skeleton: return "skeleton";
		case Type::troll: return "troll";
		case Type::vampire: return "vampire";
		case Type::zombie: return "zombie";
		default: return "???";
		}
	}

        void print() const
        {
            std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
        }
};  

namespace MonsterGenerator
{
    Monster generateMonster()
    {
        int maxIndex { Monster::Type::max_monster_types - 1 };
		auto type{ static_cast<Monster::Type>(Random::get(0, maxIndex)) };
		int hitPoints{ Random::get(1, 100) };

		static constexpr std::array s_names{ "Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans" };
		static constexpr std::array s_roars{ "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*" };

		// Remember length is one greater than index of last element
		auto name { s_names[Random::get<std::size_t>(0, s_names.size() - 1)] };
		auto roar { s_roars[Random::get<std::size_t>(0, s_roars.size() - 1)] };

		return Monster{ type, name, roar, hitPoints };
    }
}

int main()
{
	Monster m{ MonsterGenerator::generateMonster() };
	m.print();

	return 0;
}

