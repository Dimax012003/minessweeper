#include <iostream>
#include <Board.h>
#include <square.h>
#include <player.h>
using namespace std;
int main(){
  Board *a;
  a=new Board(10,10);
  player play("James");
  a->createBoard();
  do{
    square *temp;
    int x,y,i,j;
    cout<<"Enter coordinates"<<endl;
    cin>>x;
    cin>>y;
    temp=new square(x,y);
    a->showBoard();
    //a->createchoises();
    play.choose(a,a->returnsquare(x,y),x,y);

    if(play.found(a->returnsquare(x,y),x,y)==true){
       a->setsquare(a->returnsquare(x,y),x,y);
       a->showBoard();
       //a->returnsquare(x,y)->setchar(x,y,'O');
    }
    else if(play.found(a->returnsquare(x,y),x,y)==false){

        a->setsquare(a->returnsquare(x,y),x,y);
        a->showBoard();

    }

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"total score"<<" "<<play.score()<<endl;
  }while(play.returnbombs()<19 || play.returntries()<70);
};
/* if(squares[i][j+1]->getchar=='O'){
                k++;
            }
            if(squares[i][j-1]->getchar=='O'){
                k++;
            }
            if(squares[i-1][j]->getchar=='O'){
                k++;
            }
            if(squares[i+1][j]->getchar=='O'){
                k++;
            }
            if(squares[i+1][j+1]->getchar=='O'){
                k++;
            }
            if(squares[i-1][j-1]->getchar=='O'){
                k++;
            }
            if(squares[i-1][j+1]->getchar=='O'){
                k++;
            }
           if(squares[i+1][j-1]->getchar=='O'){
                k++;
            }
           if(squares[i][j+1]->getchar=='O'){
                k++;
            }
            */
