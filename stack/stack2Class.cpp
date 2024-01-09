#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size){
        arr=new int[size];
        this->size=size;
        top1=-1;
        top2=size;
    }

    // functions
    void push1(int data){
        if(top2-top1 ==1){
            // space not available 
            cout<<"Stack overflow in stack 1"<<endl;
        }
        else{
            top1++;
            arr[top1]=data;
        }
    }

    void pop1(){
        if(top1==-1){
            cout<<"Stack underflow in stack 1"<<endl;
        }
        else{
            top1--;
        }
    }

    void push2(int data){
        if(top2-top1 ==1){
            // space not available 
            cout<<"Stack overflow in stack 2"<<endl;
        }
        else{
            top2--; 
            arr[top2]=data;
        }
    }

    void pop2(){
        if(top2==-1){
            cout<<"Stack underflow in stack 2"<<endl;
        }
        else{
            top2++;
        }
    }
};

int main(){
    Stack s(10);
    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push1(40);
    s.push1(50);

    s.push2(110);
    s.push2(120);
    s.push2(130);
    s.push2(140);
    s.push2(150);
    s.push1(1000);
}