#include<iostream>
using namespace std;

class DeQueue{
    public:
    int size;
    int *arr;
    int front;
    int rear;

    DeQueue(int size){
        this->size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
    }

    void pushRear(int data){
        if(front==0 && rear==size-1){
            cout<<"Queue is full!"<<endl;
            return;
        }
        // single element case ie first element
        else if(front==-1){
            front=rear=0;
            
        }
        // circular nature
        else if(rear==size-1 && front!=0){
            rear=0;
            
        }
        else{
            rear++;
           
        }
        arr[rear]=data;
    }

    void pushFront(int data){
        if(front==0 && rear==size-1){
            cout<<"Queue is full!"<<endl;
            return;
        }
        // single element case ie first element
        else if(front==-1){
            front=rear=0;
            
        }
        // circular nature
        else if(front==0 && rear!=size-1){
            front=size-1;
            
        }
        else{
            front--;
           
        }
        arr[front]=data;
    }

    void popFront(){
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

    void popEnd(){
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
        else if(rear==0){
            rear=size-1;
        }
        else{
            rear--;
        }
    }
};