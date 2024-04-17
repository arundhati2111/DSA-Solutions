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

class Professor:public Teacher,public Researcher{
    void motivate(){
        cout<<"Motivating"<<endl;
    }
};

int main(){
    Professor p;
    // diamond problem 
    // 1: scope resolution
    // p.Teacher::walk();
    // p.Researcher::walk();
    // 2: virtual 
    p.walk();
}