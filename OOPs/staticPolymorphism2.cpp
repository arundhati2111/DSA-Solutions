#include<iostream>
#include<string>
#include<vector>
using namespace std;

// operator overloading
class Vector{
    int x,y;
    public:
        Vector(int x,int y):x(x),y(y){}

        void display(){
            cout<<"x: "<<x<<" y: "<<y<<endl;
        }

        void operator+(const Vector &src){
            this->x=this->x+src.x;
            this->y=this->y+src.y;
        }
};

int main(){
    Vector v1(2,3);
    Vector v2(4,5);
    v1+v2;
    v1.display();
}