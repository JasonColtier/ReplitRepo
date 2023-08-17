//
// Created by User on 17/08/2023.
//

#ifndef REPLITREPO_TILE_H
#define REPLITREPO_TILE_H

#include "Point2D.h"
#include <iostream>

class Tile {

public:
    explicit Tile(int value) : m_value(value) {}

    int getNum() const { return m_value; };
    //Point2D getPosition();

    bool isEmpty() const{
        return m_value == 0;
    };

    friend std::ostream& operator<<(std::ostream& ostream,const Tile& tile);


private:
    //the tile's value from 0 to 15
    const int m_value{};

    //Point2D m_position{};
};

std::ostream& operator<<(std::ostream& ostream,const Tile& tile){
    ostream<<" ";//one space before

    if(tile.isEmpty()){
        return ostream<<"   ";//3 spaces
    }

    //is tile is one number digit we add one space for alignement
    if(tile.m_value<10)
        ostream<<" ";

    ostream<<tile.m_value;

    ostream<<" ";//one space after
    return ostream;
}


#endif //REPLITREPO_TILE_H
