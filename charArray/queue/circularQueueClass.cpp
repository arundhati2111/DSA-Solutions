#include<iostream>
using namespace std;

class CirQueue{
    public:
    int size;
    int *arr;
    int front;
    int rear;

    CirQueue(int size){
        this->size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
    }

    void push(int data){
        // queue is full 
        if(front==0 && rear==size-1){
            cout<<"Queue is full!"<<endl;
            return;
        }
        // single element case ie first element
        else if(front==-1){
            front=rear=0;
            arr[rear]=data;
        }
        // circular nature
        else if(rear==size-1 && front!=0){
            rear=0;
            arr[rear]=data;
        }
        else{
            rear++;
            arr[rear]=data;
        }

    }

    void pop(){
        // queue is empty
        if(front==-1){
            cout<<"Queue is empty"<<endl;
        }
        // single element
        else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
        }
        // circular nature
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
    }
};