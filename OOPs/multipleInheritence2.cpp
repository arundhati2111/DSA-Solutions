#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Person{
    public:
    void walk(){
        cout<<"Walking"<<endl;
    }
};

class Teacher:virtual public Person{
    public:
    void teach(){
        cout<<"Teaching"<<endl;
    }
};

class Researcher:virtual public Person{
    public:
    void research(){
        cout<<"Researching"<<endl;
    }
};

class Professor:public Teacher,public Researcher,virtual public Person{
    void motivate(){
        cout<<"Motivating"<<endl;
    }
};

int main(){
    Professor p;
    p.walk();
}