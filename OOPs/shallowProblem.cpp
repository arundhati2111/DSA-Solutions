#include<iostream>
using namespace std;

class abc{
    public:
        int x;
        int *y;

        abc(int _x,int _y):x(_x),y(new int(_y)){} //initialisation list

        void print() const{
            printf("X:%d\nPTR Y:%p\nContent of y:%d\n\n",x,y,*y);
        }

        abc(const abc&obj){
            x=obj.x;
            y=obj.y;
        }
        ~abc(){
            delete y;  //deleting dynamically allocated memory 
        }
};

int main(){
    abc *a= new abc(1,2);
    abc b=*a;
    delete a;
    b.print();
}