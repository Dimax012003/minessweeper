#include "Board.h"
#include <iostream>
using namespace std;
#include <cstdlib>
#include "time.h"
Board::Board(int sizex,int sizey)
{
    this->sizex=10;
    this->sizey=10;
    int i,j;
    squares=new square**[sizex];
    for(i=0;i<sizex;i++){
        squares[i]=new square*[sizey];
    }
    for(i=0;i<sizex;i++){
        for(j=0;j<sizey;j++){
            squares[i][j]=new square(i,j);
        }
    }
}

Board::~Board()
{
   int i,j;
   for(i=0;i<sizex;i++){
     for(j=0;j<sizey;j++){
        delete squares[i][j];
     }
   }
   for(i=0;i<sizex;i++){
    delete[] squares[i];
   }
   delete[] squares;
}
int Board::getsizex(){
  return sizex;
}
int Board::getsizey(){
  return sizey;
}
void Board::createBoard(){
   for(int i=0;i<sizex;i++){
    for(int j=0;j<sizey;j++){
       squares[i][j]->setchar(i,j,'-');
    }
   }
   int b,a,i=0;
   srand(time(NULL));
   do{
    i++;
    b=rand()%10;
    a=rand()%10;
    squares[a][b]->setchar(a,b,'O');
   }while(i<20);

}
void Board::showBoard(){
 int i,j;
 for(i=0;i<sizex;i++){
    for(j=0;j<sizey;j++){
      if(squares[i][j]->getchar()=='#'  ){
        cout<<"O"<<"       ";
      }
      else if( squares[i][j]->getchar()!='O' && squares[i][j]->getchar()!='-' && squares[i][j]->getchar()!='#' ){

        cout<<squares[i][j]->getchar()<<"       ";
      }
      else   cout<<"-"<<"       ";

    }
    cout<<endl;
    cout<<endl;

  }
}
int Board::findbombs(square *sqr,int i,int j){
    int k=0,row,col;
    if(sqr->isempty(i,j)==true){
        if(i!=0 || i!=9 ){
            for(row=i-1;row<i+2;row++){
                for(col=j-1;col<j+2;col++){
                   if(squares[row][col]->getchar()=='O' || squares[row][col]->getchar()=='#'){
                       k++;
                   }
                }
             }
        }
      else if(i==0){

            if(j!=9 || j!=0){
            for(row=i;row<i+2;row++){
                for(col=j-1;col<j+2;col++){
                   if(squares[row][col]->getchar()=='O' || squares[row][col]->getchar()=='#'){{

                       k++;
                   }
                }
             }
        }
        if(j==9){

            if(squares[i][j-1]->getchar()=='O' || squares[i][j-1]->getchar()=='#'){
                k++;
            }
            if(squares[i+1][j]->getchar()=='O' || squares[i+1][j]->getchar()=='#'){
                k++;
            }
            if(squares[i+1][j-1]->getchar()=='O' ||squares[i+1][j-1]->getchar()=='#'){
                k++;
            }
        }
      else  if(j==0){
            if(squares[i][j+1]->getchar()=='O' || squares[i][j+1]->getchar()=='#' ){
                k++;
            }
            if(squares[i+1][j]->getchar()=='O' || squares[i+1][j]->getchar()=='O'){
                k++;
            }
            if(squares[i+1][j+1]->getchar()=='O' || squares[i+1][j+1]->getchar()=='#'){
                k++;
            }
        }
    }
    if(i==9){
        if(j<=8 &&j>=1){
            for(row=i;row>i-2;row--){
                for(col=j-1;col<j+2;col++){
                   if(squares[row][col]->getchar()=='O' || squares[row][col]->getchar()=='#'){
                       k++;
                   }
                }
             }
        }
        if(j==0){
            if(squares[i-1][j]->getchar()=='O' || squares[i-1][j]->getchar()=='#'){
                k++;
            }
            if(squares[i-1][j+1]->getchar()=='O' ||squares[i-1][j+1]->getchar()=='#' ){
                k++;
            }
            if(squares[i][j+1]->getchar()=='O' || squares[i][j+1]->getchar()=='#'){
                k++;
            }
        }
       else if(j==9){
            if(squares[i-1][j]->getchar()=='O' || squares[i-1][j]->getchar()=='#'){
                k++;
            }
            if(squares[i][j-1]->getchar()=='O' || squares[i][j-1]->getchar()=='#'){
                k++;
            }
            if(squares[i-1][j-1]->getchar()=='O' ||squares[i-1][j-1]->getchar()=='#' ){
                k++;
            }
       }
    }
 }
}
return k;
}
void Board::setsquare(square *t,int i,int j){
 if(t->isempty(i,j)==false){squares[i][j]->setchar(i,j,'#');}
 else if(t->isempty(i,j)==true){placenum(squares[i][j],i,j);}

}

square *Board::returnsquare(int i,int j){
 return squares[i][j];
}
void Board::placenum(square *sqr,int i,int j){

  switch(findbombs(sqr,i,j)){
  case 0:
      sqr->setchar(i,j,'0');
      break;
  case 1:
      sqr->setchar(i,j,'1');
      break;
  case 2:
      sqr->setchar(i,j,'2');
      break;
  case 3:
      sqr->setchar(i,j,'3');
      break;
   case 4:
      sqr->setchar(i,j,'4');
      break;
   case 5:
      sqr->setchar(i,j,'5');
      break;
   case 6:
      sqr->setchar(i,j,'6');
      break;
   case 7:
      sqr->setchar(i,j,'7');
      break;
  case 8:
      sqr->setchar(i,j,'8');
      break;
  default:
    break;
  }

}


