#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "square.h"
#include "Board.h"
using namespace std;
class player
{
    public:
        player(string name);
        virtual ~player();
        bool found(square *sqr,int i,int j);
        void choose(Board *a,square *sqr,int i,int j);
        int returntries();
        int returnbombs();
        string returnname();
        int score();
    private:
        int numoftries;
        string name;
        int bombs;
        bool bomb;
};

#endif // PLAYER_H
