#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Bird{
    public:
    int age,weight,nol; //nol-->number of legs
    string color;

    void eat(){
        cout<<"Bird is eating"<<endl;
    }

    void fly(){
        cout<<"Bird is flying"<<endl;
    }
};

class Sparrow:private Bird{
    public:
    Sparrow(int age,int weight, string color, int nol){
        this->age=age;
        this->color=color;
        this->weight=weight;
        this->nol=nol;
    }
    void grassing(){
        cout<<"Sparrow is grassing"<<endl;
    }   

    int getNol(){
        return this->nol;
    } 
};

int main(){
    
    // p.grassing(); not possible to access other child class's functionss
}