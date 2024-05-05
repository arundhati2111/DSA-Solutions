#if !defined(BIRD_H)
#define BIRD_H
#include<iostream>

class Bird{
    public:
        virtual void fly()=0;
        virtual void eat()=0; //pure virtual functions
};

class Sparrow:public Bird{
    public:
        void fly(){
            std::cout<<"Sparrow is flying\n";
        }
        void eat(){
            std::cout<<"Sparrow is eating seeds\n";
        }
};

class Eagle:public Bird{
    public:
        void fly(){
            std::cout<<"Eagle is flying\n";
        }
        void eat(){
            std::cout<<"Eagle is eating snakes\n";
        }
};

#endif