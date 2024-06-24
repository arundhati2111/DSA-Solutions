#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        int frontElement=q.front();
        q.pop();

        s.push(frontElement);
    }

    while(!s.empty()){
        int element=s.top();
        s.pop();

        q.push(element);
    }
    return;
}

void reverse(queue<int> &q){
    // base case
    if(q.empty()){
        return;
    }
    int element=q.front();
    q.pop();
    reverse(q);

    q.push(element);
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    // cout<<"Printing original queue"<<endl;
    // while(!q.empty()){
    //     int element=q.front();
    //     q.pop();
    //     cout<<element<<" ";
    // }cout<<endl;

    // reverseQueue(q);

    reverse(q);

    cout<<"Printing reversed queue"<<endl;
    while(!q.empty()){
        int element=q.front();
        q.pop();
        cout<<element<<" ";
    }cout<<endl;
}