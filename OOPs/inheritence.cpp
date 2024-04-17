#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Bird{
    public:
    int age,weight;
    int nol;  //number of legs
    string color;

    void eat(){
        cout<<"Bird is eating"<<endl;
    }

    void fly(){
        cout<<"Bird is flying"<<endl;
    }
};

class Sparrow:public Bird{
    public:
    Sparrow(int age,string color){
        this->age=age;
        this->color=color;
    }
    void grassing(){
        cout<<"Sparrow is grassing"<<endl;
    }    
};

class Piegon:public Bird{
    public:
    void guttering(){
        cout<<"Piegon is guttering"<<endl;
    }    
};

int main(){
    Piegon p;
    Sparrow s(1,"Brown");
    cout<<s.color<<endl;
    s.grassing();
    // p.grassing(); not possible to access other child class's functionss
}