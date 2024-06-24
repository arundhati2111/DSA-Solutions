#include<iostream>
using namespace std;

class Deque{
    public:
        int *arr;
        int size;
        int front;
        int rear;

        Deque(int size){
            arr=new int[size];
            this->size=size;
            front=-1;
            rear=-1;
        }

        void pushFront(int val){
            // overflow
            if((front==0 && rear==size-1) || (rear==front-1)){
                cout<<"Queue overflow"<<endl;
            }
            else if(front==-1 && rear==-1){
                front++;
                rear++;
                arr[front]=val;
            }
            else if(front==0 && rear!=size-1){
                front=size-1;
                arr[front]=val;
            }
            else{
                front--;
                arr[front]=val;
            }
        }
        void pushBack(int val){
            // overflow
            if((front==0 && rear==size-1) || (rear==front-1)){
                cout<<"Queue overflow"<<endl;
            }
            // empty queue
            else if(front==-1 && rear==-1){
                front++;
                rear++;
                arr[rear]=val;
            }
            // circular nature
            else if(rear==size-1 && front!=0){
                rear=0;
                arr[rear]=val;
            }
            // normal
            else{
                rear++;
                arr[rear]=val;
            }

        }
        void popFront(){
            // underflow
            if(front==-1 && rear==-1){
                cout<<"Queue underflow"<<endl;
            }
            // single element
            else if(front==rear){
                front=-1;
                rear=-1;
            }
            // circular nature
            else if(front==size-1){
                arr[front]=-1;
                front=0;
            }
            // normal
            arr[front]=-1;
            front++;
        }
        void popBack(){
            // underflow
            if(front==-1 && rear==-1){
                cout<<"Queue underflow"<<endl;
            }
            // single element
            else if(front==rear){
                arr[rear]=-1;
                front=-1;
                rear=-1;
            }
            // circular nature
            if(rear==0){
                arr[rear]=-1;
                rear=size-1;
            }
            // normal condition
            else{
                arr[rear]=-1;
                rear--;
            }
        }
};