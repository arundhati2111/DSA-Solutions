#include<iostream>
using namespace std;

class A{
    int x;
    public:
        A(int val):x(val){}

        int getX() const{
            return x;
        }

        void setX(int val){
            x=val;
        }

        friend class B;
        friend void print(const A &);  //declaration
};

class B{
    public:
        void print(const A &a){
            cout<<"Accessed using friend class "<<a.x<<endl;
        }
};

void print(const A &a){
    cout<<"Accesses using friend function "<<a.x<<endl;
}

int main(){
    A a(5);
    B b;
    b.print(a);
    print(a);
}