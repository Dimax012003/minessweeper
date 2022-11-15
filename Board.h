#ifndef BOARD_H
#define BOARD_H
#include "square.h"
#include <string>

class Board
{
    public:
        Board(int sizex,int sizey);
        virtual ~Board();
        int getsizex();
        int getsizey();
        void createBoard();
        void showBoard();
        int  findbombs(square *sqr,int i,int j);
        void setsquare(square *t,int i,int j);
        square *returnsquare(int i,int j);

        void placenum(square *sqr,int i,int j);


    private:
        int sizex;
        int sizey;

        square ***squares;

};

#endif // BOARD_H
