#include<iostream>
using namespace std;

class Animal{
    public:
    virtual void sound(){
        cout<<"Animals make sound"<<endl;
    }
    virtual ~Animal(){
        cout<<"Animal dtor "<<endl;
    }
};

class Dog:public Animal{
    public:
    void sound() override {
        cout<<"barking"<<endl;
    }
    ~Dog(){
        cout<<"Dog dtor"<<endl;
    }
};

class Cat:public Animal{
    public:
    void sound(){
        cout<<"Meow"<<endl;
    }
    ~Cat(){
        cout<<"Cat dtor"<<endl;
    }
};

void sound(Animal *animal){
    animal->sound(); //polymorphic
}

int main(){
    Animal *animal=new Dog(); //parent can inherit child's object
    sound(animal);

    // animal= new Cat();
    // sound(animal);

    delete animal;
}