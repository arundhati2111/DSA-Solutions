#include<iostream>
using namespace std;

class Cqueue{
    public:
        int *arr;
        int size;
        int front;
        int rear;

        Cqueue(int size){
            arr= new int[size];
            this->size=size;
            front= -1;
            rear=-1;
        }

        void push(int val){
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

        void pop(){
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

        void print(){
            cout<<"Printing Queue: ";
            for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";
            }cout<<endl;
        }
};

int main(){
    Cqueue cq(5);
    cq.print();

    cq.push(10);
    cq.push(20);
    cq.push(30);
    cq.push(40);
    cq.push(50);
    cq.print();
    cq.push(60);

    cq.pop();
    cq.pop();
    cq.pop();
    cq.print();

    cq.push(100);
    cq.print();
    cq.push(101);
    cq.print();
    cq.push(102);
    cq.print();
    cq.push(130);
    cq.print();
}