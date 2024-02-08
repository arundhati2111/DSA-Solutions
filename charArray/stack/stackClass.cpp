#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;

    // constructor 
    Stack(int size){
        arr=new int[size];
        this->size=size;
        top=-1;
    }

    // functions
    void push(int data){
        if(size-top >1){
            // size available
            top++;
            arr[top]=data;
        }
        else{
            // space not available 
            cout<<"Stack Overflow"<<endl;
        }

    }
    // top==size-1 stack overflow

    void pop(){
        if(top==-1){
            // stack is empty
            cout<<"Stack underflow"<<endl;
        }
        else{
            top--;
        }
    }

    int getTop(){
        if(top==-1){
            cout<<"There is no element in stack"<<endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }

    int getSize(){
        return top+1;
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){
    // creation
    Stack s(5);

    // insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<<"Size "<<s.getSize()<<endl;

    // print all the elements 
    while(!s.isEmpty()){
        cout<<s.getTop()<<" ";
        s.pop();
    }cout<<endl;

    cout<<"Size "<<s.getSize()<<endl;

    s.pop();
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    while(!s.isEmpty()){
        cout<<s.getTop()<<" ";
        s.pop();
    }cout<<endl;
}