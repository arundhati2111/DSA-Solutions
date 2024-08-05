#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq; //max heap created

    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);

    cout<<"Top element is "<<pq.top()<<endl;

    pq.pop();
    cout<<"Top element is "<<pq.top()<<endl;

    cout<<"Size of heap is "<<pq.size()<<endl;

    if(pq.empty()){
        cout<<"Priority queue is empty"<<endl;
    }
    else{
        cout<<"Priority queue is not empty"<<endl;
    }
}