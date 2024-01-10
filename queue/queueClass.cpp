#include<iostream>
using namespace std;

class Queue{
    public:
        int size;
        int *arr;
        int front;
        int rear;
        Queue(int size){
            this->size=size;
            arr=new int[size];
            front=0;
            rear=0;
        }

        void push(int data){
            if(rear==size){
                cout<<"Queue is full"<<endl;
            }
            else{
                arr[rear]=data;
                rear++;
            }
        }

        void pop(){
            if(front==rear){
                cout<<"Queue is empty"<<endl;
            }
            else{
                arr[front]=-1;
                front++;
                if(front==rear){
                    front=0;
                    rear=0;
                }
            }
        }

        int getFront(){
            if(front==rear){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            else{
                return arr[front];
            }
        }

        bool isEmpty(){
            if(front == rear){
                return true;
            }
            else{
                return false;
            }
        }

        int getSize(){
            return rear-front;
        }
};

int main(){
    Queue q(10);

    // insertion
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    cout<<"Size is: "<<q.getSize()<<endl;

    // deletion
    q.pop();

    cout<<"Front: "<<q.getFront()<<endl;
}