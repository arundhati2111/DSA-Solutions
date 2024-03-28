#include<iostream>
using namespace std;

class abc{
    public:
        static int x,y;

        void print(/*this pointer passed as hidden parameter*/){
            cout<<x<<" "<<y<<endl;
        }
};

int abc::x=55;
int abc::y=66;

int main(){
    abc obj1;
    obj1.x=1;
    obj1.y=2;
    obj1.print();

    abc obj2;
    obj2.x=10;
    obj2.y=20;
    obj1.print();
    obj2.print();
}