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

        // shallow copy ctor
        // abc(const abc&obj){
        //     x=obj.x;
        //     y=obj.y;
        // }

        // deep copy ctor
        abc(const abc &obj){
            x=obj.x;
            y=new int(*obj.y);
        }
};

int main(){
    abc a(1,2);
    a.print();

    abc b=a;
    b.print();

    *b.y=20;

    a.print();
    b.print();
}