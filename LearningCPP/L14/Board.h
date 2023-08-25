//
// Created by User on 17/08/2023.
//

#ifndef REPLITREPO_BOARD_H
#define REPLITREPO_BOARD_H

#include "Tile.h"
#include <cassert>

class Board {

public:

    //we create our tiles and fill the array
    explicit Board() {
        for (int i = 0; i < m_sizeGrid; ++i) {
            for (int j = 0; j < m_sizeGrid; ++j) {
                m_tiles[i][j] = new Tile{i * m_sizeGrid + j};
            }
        }
    }

    ~Board() {
        for (int i = 0; i < m_sizeGrid; ++i) {
            for (int j = 0; j < m_sizeGrid; ++j) {
                delete m_tiles[i][j];
            }
        }
    }

    //printing the board
    friend std::ostream& operator<<(std::ostream& ostream, const Board& board) {

        for (int i = 0; i < m_sizeGrid; ++i) {
            for (int j = 0; j < m_sizeGrid; ++j) {
                ostream << *board.m_tiles[i][j];
            }
            ostream << "\n";//we jump a line every m_sizeGrid
        }
        return ostream;
    }

    bool moveTile(Direction direction) {
        Point2D emptyCoo = getEmptyTileCoordinates();
        Point2D desiredNewLocation = emptyCoo.getAdjacentPoint(-direction);
//        std::cout<<"empty coo"<<emptyCoo<<"\n";
//        std::cout<<"point returned"<<desiredNewLocation<<"\n";

        if (isValidCoordinates(desiredNewLocation)) {
            swapTiles(emptyCoo, desiredNewLocation);
            return true;
        }
        return false;
    }

    void randomizeBoard() {
        for (int i = 0; i < m_randomizeIterations; ++i) {
            moveTile(Direction::GetRandomDirection());
        }
    }

    bool isPuzzleSolved() {

        Tile* previoustile = nullptr;

        for (int i = 0; i < m_sizeGrid; ++i) {
            for (int j = 0; j < m_sizeGrid; ++j) {
                if(previoustile == nullptr){

                }else if(m_tiles[i][j]->getNum() != previoustile->getNum()+1){
                    std::cout<<"current tile "<<m_tiles[i][j]->getNum()<<"!="<<previoustile->getNum()+1<<"\n";
                    return false;
                }
                previoustile = m_tiles[i][j];
            }
        }

        return true;
    }

private:

    //the size of the board
    static constexpr int m_sizeGrid = 4;
    static constexpr int m_randomizeIterations = 100;

    //our board
    Tile* m_tiles[m_sizeGrid][m_sizeGrid]{};

    Point2D getEmptyTileCoordinates() const {
        for (int i = 0; i < m_sizeGrid; ++i) {
            for (int j = 0; j < m_sizeGrid; ++j) {
                if (m_tiles[i][j]->isEmpty()) {
                    return Point2D(i, j);
                }
            }
        }
        assert(false && "no empty tile found !");
        return Point2D();
    }

    void swapTiles(Point2D& coo1, Point2D& coo2) {
        Tile* tmp = m_tiles[coo1.X][coo1.Y];
        m_tiles[coo1.X][coo1.Y] = m_tiles[coo2.X][coo2.Y];
        m_tiles[coo2.X][coo2.Y] = tmp;
    }

    //if our point is valid
    bool isValidCoordinates(const Point2D& point2D) const {
        if (point2D.X >= 0 && point2D.X < m_sizeGrid && point2D.Y >= 0 && point2D.Y < m_sizeGrid)
            return true;
        return false;
    }

};


#endif //REPLITREPO_BOARD_H
