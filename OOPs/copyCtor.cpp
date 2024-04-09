#include<iostream>
using namespace std;

class Student{
private:
    int salary;
public:
    int id;
    int age;
    bool present;
    string name;
    int nos; //number of subjects 

    // DEFAULT CONSTRUCTOR 
    Student(){
        cout<<"Default Student Constructor called"<<endl;
    }

    // PARAMETERIZED CONSTRUCTOR 
    Student(int _id,int _age,bool _present, string _name, int _nos,int _salary){
        id=_id;
        age=_age;
        present=_present;
        name=_name;
        nos=_nos;
        salary=_salary;
        cout<<"Parameterized Student Constructor called"<<endl;
    }

    Student(int _id,int _age,bool _present, string _name, int _nos){
        id=_id;
        age=_age;
        present=_present;
        name=_name;
        nos=_nos;
        cout<<"2nd Parameterized Student Constructor called"<<endl;
    }

    // COPY CTOR
    Student(const Student &srcobj){
        cout<<"Copy ctor called"<<endl;
        this->age=srcobj.age;
        this->id=srcobj.id;
        this->present=srcobj.present;
        this->name=srcobj.name;
        this->nos=srcobj.nos;
        this->salary=srcobj.salary;
    }
};

int main(){
   Student s1(1,12,1,"Arundhati",5,5000000); 
   Student s2=s1; 
//    Student s2; 
//    s2=s1;
   cout<<s1.name<<endl;
   cout<<s2.name<<endl;
}