#include<iostream>
using namespace std;

class Queue{
    public:
        int *arr;
        int size;
        int front;
        int rear;

        Queue(int size){
            arr=new int[size];
            this->size=size;
            front=-1;
            rear=-1;
        }

        void push(int val){
            // check full
            if(rear==size-1){
                cout<<"Queue overflow"<<endl;
                return;
            }
            else if(front==-1 && rear==-1){
                // empty case
                front++;
                rear++;
                arr[rear]=val;
            }
            else{
                // not full 
                rear++;
                arr[rear]=val;
            }
        }

        void pop(){
            // undeflow 
            if(front==-1 && rear==-1){
                cout<<"Queue underflow"<<endl;
                return;
            }
            else if(rear==front){
                // single element
                arr[front]=1;
                front=-1;
                rear=-1;
            }
            else{
                // normal case
                arr[front]=-1;
                front++;
            }
        }

        bool isEmpty(){
            if(front==-1 && rear==-1){
                return true;
            }
            else{
                return false;
            }
        }

        int getSize(){
            if(front==-1 && rear==-1){
                return 0; //empty queue
            }
            return rear-front+1;
        }

        int getFront(){
            if(front==-1){
                cout<<"Queue is empty, cannot give front element"<<endl;
                return -1;
            }
            else{
                return arr[front];
            }
        }

        int getRear(){
            if(rear==-1){
                cout<<"Queue is empty, cannot give rear element"<<endl;
                return -1;
            }
            else{
                return arr[rear];
            }
        }

        void print(){
            cout<<"Printing Queue: ";
            for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";
            }cout<<endl;
        }


};

int main(){
    // creation
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.print();

    cout<<"Size of queue is "<<q.getSize()<<endl;

    cout<<"Rear element is "<<q.getRear()<<endl;
    
    q.pop();
    q.print();
    
    cout<<"Size of queue is "<<q.getSize()<<endl;

    cout<<"Queue is empty(1) or not(0): "<<q.isEmpty()<<endl;

    q.push(100);
    q.pop();
    q.pop();
    q.pop();
    q.print();
    cout<<"Front element "<<q.getFront()<<endl;
    q.pop();
    q.print();
    cout<<"Size of queue: "<<q.getSize()<<endl;
    cout<<"Rear element is "<<q.getRear()<<endl;
    return 0;
}