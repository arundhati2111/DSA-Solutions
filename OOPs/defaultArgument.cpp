#include<iostream>
using namespace std;

class abc{
    int x;
    int *y;
    int z;

    public:
        abc(int _x,int _y,int _z=0){
            x=_x;
            y=new int(_y);
            z=_z;
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
        int getZ() const{
            return z;
        }
        void setZ(int __val){
            z=__val;
        }
};

void printABC(const abc &a){
    cout<<a.getX()<<" "<<a.getY()<<" "<<a.getZ()<<endl;
}

int main(){
    // abc a;
    abc a(1,2);
    printABC(a);
    abc b(4,5,6);
    printABC(b);
}