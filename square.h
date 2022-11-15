#ifndef SQUARE_H
#define SQUARE_H


class square
{
   public:
        square(int x,int y);
        int getx();
        int gety();
        char getchar();
        void setchar(int i,int j,char a);
        bool isempty(int i,int j);
        virtual ~square();

    private:
       char a;
       int x;
       int y;
};

#endif // SQUARE_H
