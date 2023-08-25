//
// Created by User on 17/08/2023.
//

#ifndef REPLITREPO_POINT2D_H
#define REPLITREPO_POINT2D_H

#include "Direction.h"
#include <iostream>

struct Point2D {

    int X;
    int Y;

    explicit Point2D(int x = 0, int y = 0) : X(x), Y(y) {}

    Point2D getAdjacentPoint(Direction direction) const {
        switch (direction.getDirection()) {
            case Direction::top :
                return Point2D{X-1,Y};
            case Direction::down :
                return Point2D{X+1,Y};
            case Direction::left :
                return Point2D{X,Y-1};
            case Direction::right :
                return Point2D{X,Y+1};
            default:
                std::cerr<<"wrong direction provided, returning same point";
                return *this;
        }
    }

    bool operator==(const Point2D& otherPoint) const {
        return otherPoint.X == this->X && otherPoint.Y == this->Y;
    }

    bool operator!=(const Point2D& otherPoint) const {
        return !(otherPoint==*this);
    }

    friend std::ostream& operator<<(std::ostream& ostream, const Point2D& point2D){
        return ostream<<"{"<<point2D.X<<","<<point2D.Y<<"}";
    }

};


#endif //REPLITREPO_POINT2D_H
