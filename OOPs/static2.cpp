#include<iostream>
using namespace std;

class abc{
    public:
        static int x,y;
        // abc():x(0),y(0){}

        static void print(){
            printf("Inside static %s\n",__FUNCTION__);
            cout<<x<<" "<<y<<endl;
        }

};
int abc::x=55;
int abc::y=44;

int main(){
    abc obj1;
    abc::print();
    abc obj2;
    abc::print();
}