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
    int *v;

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
        this->v=new int(10);
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
    ~Student(){
        cout<<"Dtor called"<<endl;
        delete v;
    }
};

int main(){
   {
   Student s2(30,20,1,"Arundhati",5,5000000); //parameterized constructor called
   } //destructor called
   Student s1; //default constructor called
   return 0; //destructor called
    
}