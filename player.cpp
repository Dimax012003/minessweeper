#include "player.h"
#include <iostream>
using namespace std;
#include "Board.h"
player::player(string name)
{
    this->name=name;
    numoftries=0;
    bombs=0;
    bomb=false;
}
player::~player()
{
    name="-";
}
void player::choose(Board *a,square *sqr,int i,int j){

  if(sqr->isempty(i,j)==true){
        cout<<"Missed"<<endl;
        cout<<"Nummber of bombs around "<<a->findbombs(sqr,i,j)<<endl;
        bomb=false;
  }
   if(sqr->isempty(i,j)==false){
        cout<<"bomb found!"<<endl;
        bombs++;
        bomb=true;

    }
    numoftries++;

}
int player::returntries(){
  return numoftries;
}
int player::returnbombs(){
  return bombs;
}
bool player::found(square *sqr,int i,int j){
 if(bomb==true && sqr->isempty(i,j)==false && sqr->getchar()!='#' ){

    return true;
 }
 return false;
}
int player::score(){
 int i,sum=0;
 for(i=0;i<returntries();i++){
    if(returntries()>=10 && returntries()<=40 && bombs>=3){
        sum=sum+15;
    }
 }
 for(i=0;i<bombs;i++){
    sum=sum+5;
 }
 if(returntries()>=40 && bomb==false){
    for(i=30;i<returntries();i++){
        sum=sum-8;
    }
 }
 return sum;
}
