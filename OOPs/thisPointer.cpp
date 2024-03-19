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
    Student(int id,int age,bool present, string name, int nos,int salary){
        this->id=id;
        this->age=age;
        this->present=present;
        this->name=name;
        this->nos=nos;
        this->salary=salary;
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
};

int main(){
   Student s1;
   Student s2(30,20,1,"Arundhati",5,5000000);
   Student s3(11,22,0,"Pratham",5);
   cout<<s2.name<<endl;
   cout<<s2.id<<endl;
   
   cout<<s3.name<<endl;
    // cout<<s.salary; is not possible because salary is private member of class 

    Student *s4=new Student(3,34,1,"Gauri",6);
    cout<<s4->name<<endl;
    cout<<(*s4).name<<endl;

    delete s4;
}