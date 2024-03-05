#include<iostream>
using namespace std;

class empty{

};

class Student{
private:
    int marks;
public:
    int id;
    int age;
    string name;
    int nos; //number of subjects 

    void study(){
        cout<<"Studying"<<endl;
    }

    void sleep(){
        cout<<"Sleeping"<<endl;
    }

    void gaming(){
        cout<<"Playing game"<<endl;
    }
};

int main(){
    cout<<"Size of class: "<<sizeof(Student)<<endl;
    cout<<"Size of empty class: "<<sizeof(empty)<<endl;
    Student s1;
    s1.id=23;
    s1.age=17;
    s1.name="Arundhati";
    s1.nos=5;
    // s1.marks cant be accessed because private

    Student s2;
    s2.age=12;
    s2.name="Pratham";
}