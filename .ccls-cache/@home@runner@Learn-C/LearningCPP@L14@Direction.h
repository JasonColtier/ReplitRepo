//
// Created by User on 18/08/2023.
//

#ifndef REPLITREPO_DIRECTION_H
#define REPLITREPO_DIRECTION_H

#include "Random.h"
#include "iostream"

class Direction {

public:
    enum Cardinality {
        top,
        down,
        left,
        right,
        max_direction,
    };

    explicit Direction(Cardinality cardinality) : m_dir(cardinality) {};

    Cardinality getDirection() {
        return m_dir;
    }

    //print
    friend std::ostream& operator<<(std::ostream& ostream, const Direction& direction);

    //we return the oposite direction
    Direction operator-() {
        switch (m_dir) {
            case top:
                return Direction{down};
            case down:
                return Direction{top};
            case left:
                return Direction{right};
            case right:
                return Direction{left};
        }
    }

    //returns a random direction object
    static Direction GetRandomDirection() {
        return Direction(
                static_cast<Direction::Cardinality>(Random::get(0, Direction::Cardinality::max_direction - 1)));
    };

private:
    Cardinality m_dir{};

};

std::ostream& operator<<(std::ostream& ostream, const Direction& direction) {
    switch (direction.m_dir) {
        case Direction::top:
            ostream << "top";
            break;
        case Direction::down:
            ostream << "down";
            break;
        case Direction::left:
            ostream << "left";
            break;
        case Direction::right:
            ostream << "right";
            break;
        case Direction::max_direction:
            ostream << "error max direction";
            break;
    }
    return ostream;
}


#endif //REPLITREPO_DIRECTION_H
