#include<iostream>
using namespace std;

class abc{
    mutable int x;
    public:
        int getX() const{
            x=10;
            return x;
        }
        int setX(int val){
            x=val;
        }
};

int main(){
    abc a;
    a.setX(5);
    cout<<a.getX()<<endl;
}