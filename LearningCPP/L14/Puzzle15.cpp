
#include "Tile.h"
#include "Board.h"
#include "UserInput.h"

int main(){

//    Tile tile1{ 10 };
//    Tile tile2{ 8 };
//    Tile tile3{ 0 }; // the missing tile
//    Tile tile4{ 1 };
//
//    std::cout << "0123456789ABCDEF\n"; // to make it easy to see how many spaces are in the next line
//    std::cout << tile1 << tile2 << tile3 << tile4 << '\n';
//
//    std::cout << std::boolalpha << tile1.isEmpty() << ' ' << tile3.isEmpty() << '\n';
//    std::cout << "Tile 2 has number: " << tile2.getNum() << "\nTile 4 has number: " << tile4.getNum() << '\n';

    Board board{};
    board.randomizeBoard();
    std::cout << board;



    while (true){
        char key {UserInput::getCommandFromUser()};

        //perform movement
        Direction direction {UserInput::ConvertCommandToDirection(key)};
        std::cout<<"you entered direction : " <<direction <<"\n";

        board.moveTile(direction);
        std::cout<<board;

        if(board.isPuzzleSolved()){
            std::cout<<"you won !!";
            return 0;
        }

        if(key == 'f'){
            std::cout<<"bye";
            return 0;
        }
    }


    return 0;
}