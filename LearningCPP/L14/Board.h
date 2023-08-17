//
// Created by User on 17/08/2023.
//

#ifndef REPLITREPO_BOARD_H
#define REPLITREPO_BOARD_H

#include "Tile.h"

class Board{

public:

    //we create our tiles and fill the array
    explicit Board(){
        for (int i = 0; i < m_sizeGrid; ++i) {
            for (int j = 0; j <m_sizeGrid; ++j) {
                m_tiles[i][j] = new Tile{i*m_sizeGrid+j};
            }
        }
    }

    //printing the board
    friend std::ostream& operator<<(std::ostream& ostream,const Board& board){

        for(int i = 0;i<m_sizeGrid;++i){
            for (int j = 0; j < m_sizeGrid; ++j) {
                ostream<<*board.m_tiles[i][j];
            }
            ostream<<"\n";//we jump a line every m_sizeGrid
        }
        return ostream;
    }

private:
    static constexpr int m_sizeGrid = 4;
    Tile* m_tiles[m_sizeGrid][m_sizeGrid]{};

};


#endif //REPLITREPO_BOARD_H
