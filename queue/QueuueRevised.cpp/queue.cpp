#include<iostream>
#include<queue>
using namespace std;

int main(){
    // creation
    queue<int> q;

    // insertion
    q.push(5);

    // size
    cout<<"Size of queue is "<< q.size()<<endl;

    // empty
    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }

    // remove
    q.pop();

    cout<<"Size of queue is "<< q.size()<<endl;

    q.push(10);
    q.push(20);
    q.push(30);

    cout<<"Front element of queue is "<<q.front()<<endl;

    cout<<"Last element of queue is "<<q.back()<<endl;


}