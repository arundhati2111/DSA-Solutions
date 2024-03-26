#include<iostream>
using namespace std;

class abc{
    int x;
    int *y;

    public:
        abc(){
            x=0;
            y=new int(0);
        }
        abc(int _x,int _y){
            x=_x;
            y=new int(_y);
        }
        int getX() const{
            return x;
        }
        void setX(int _val){
            x=_val;
        }
        int getY() const{
            return *y;
        }
        void setY(int _val){
            *y=_val;
        }
};

void printABC(const abc &a){
    cout<<a.getX()<<" "<<a.getY()<<endl;
}

int main(){
    // abc a;
    abc a(1,2);
    printABC(a);
    cout<<a.getX()<<endl;
    cout<<a.getY()<<endl;
}