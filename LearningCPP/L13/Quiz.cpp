//
// Created by User on 22/07/2023.
//

#include <iostream>
#include <cmath>
#include "../L7/Random.h"
#include <array>

class Point2d {

public:
    Point2d(double x = 0, double y = 0) : m_x{x}, m_y{y} {

    };

    void print() const {
        std::cout << "Point2d(" << m_x << ", " << m_x << ")\n";
    }

//    double distanceTo(const Point2d& otherPoint) const{
//        return std::sqrt((m_x - otherPoint.m_x) * (m_x - otherPoint.m_x) + (m_y - otherPoint.m_y) * (m_y - otherPoint.m_y));
//    };
    friend double distanceFrom(const Point2d& first, const Point2d& second);

private:
    double m_x{0};
    double m_y{0};
};

double distanceFrom(const Point2d& first, const Point2d& second) {
    return std::sqrt(
            (first.m_x - second.m_x) * (first.m_x - second.m_x) + (first.m_y - second.m_y) * (first.m_y - second.m_y));
};



////////////////// question 2

class HelloWorld {
private:
    char* m_data{};

public:
    HelloWorld() {
        m_data = new char[14];//un array de 14 characters
        const char* init{"Hello, World!"};//13 + 1 lettres
        for (int i = 0; i < 14; ++i)
            m_data[i] = init[i];//we fill data with init string
    }

    ~HelloWorld() {
        // replace this comment with your destructor implementation
        delete[] m_data;
    }

    void print() const {
        std::cout << m_data << '\n';
    }
};


/////////////////////////// question 3



class Monster {

public:
    enum MonsterType {
        Dragon,
        Goblin,
        Ogre,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombie,
        max_monster_types,
    };

    Monster(MonsterType type, std::string name = "unamed monster", std::string roar = "grrrrr", int HP = 0) : m_type{
            type}, m_name{name}, m_roar{roar}, m_HP{HP} {

    }

    std::string getTypeString() {
        switch (m_type) {
            case Dragon:
                return "Dragon";
            case Goblin:
                return "Goblin";
            case Ogre:
                return "Ogre";
            case Orc:
                return "Orc";
            case Skeleton:
                return "Skeleton";
            case Troll:
                return "Troll";
            case Vampire:
                return "Vampire";
            case Zombie:
                return "Zombie";
            case max_monster_types:
                return "error max monster";
        }
    }

    void print() {
        std::cout << m_name << " the " << getTypeString() << " has " << m_HP << " hit points and says " << m_roar
                  << "\n";
    }

private:

    MonsterType m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_HP{};
};

namespace MonsterGenerator {
    Monster generate() {

        static std::array<std::string, 4> s_names{
                "Samy", "Gremlinao", "tomy", "beth"
        };

        static std::array<std::string, 4> s_roars{
                "grrrr", "miaouuuuu", "waaaaththth", "bnbnbnbnbn"
        };

        return Monster{Monster::MonsterType(Random::get(0, Monster::MonsterType::max_monster_types)),
                       s_names[Random::get<std::size_t>(0, std::size(s_names) - 1)],
                       s_roars[Random::get<std::size_t>(0, std::size(s_roars) - 1)],
                       Random::get(1, 100)};
    }
}

int main() {
    Point2d first{};
    Point2d second{3.0, 4.0};
    first.print();
    second.print();
//    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    HelloWorld hello{};
    hello.print();

    Monster skeleton{Monster::Skeleton, "Bones", "*rattle*", 4};
    skeleton.print();

    for (int i{0}; i < 5; i++) {
        Monster m{MonsterGenerator::generate()};
        m.print();
    }


    return 0;
}