#include "square.h"

square::square(int x,int y)
{
    this->x=x;
    this->y=y;
    a='-';
}

square::~square()
{
    a='-';
}
int square::getx(){
    return x;
}
int square::gety(){
    return y;
}
char square::getchar(){
return a;
}
void square::setchar(int i,int j,char a){
this->a=a;
}
bool square::isempty(int i,int j){
if(a=='O' || a=='#'){
    return false;
}
else if(a=='-'){return true;}
}
