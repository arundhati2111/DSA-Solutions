#include<iostream>
using namespace std;

class Base{
    public:
    // virtual ctor not possible
    Base(){
        cout<<"Base Ctor"<<endl;
    }
    virtual ~Base(){
        cout<<"Base Dtor"<<endl;
    }
};

class Derived:public Base{
    public:
    Derived(){
        cout<<"Derived Ctor"<<endl;
    }
    ~Derived(){
        cout<<"Derived Dtor"<<endl;
    }
};

int main(){
    Base *b=new Derived();
    delete b;
}