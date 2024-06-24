#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseFirstK(queue<int> &q,int k){
    // pop k elements from queue and push in stack
    stack<int> s;
    int n=q.size();
    if(k>n || k==0){
        return;
    }
    for(int i=0;i<k;i++){
        int element=q.front();
        q.pop();
        s.push(element);
    }

    // pop from stack and push back in queue
    while(!s.empty()){
        int top=s.top();
        s.pop();
        q.push(top);
    }

    // pop n-k elements from queue and push back
    for(int i=0;i<(n-k);i++){
        int front=q.front();
        q.pop();
        q.push(front);
    }
    return;
}

int main(){
    queue<int> q;
    stack<int> s;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    reverseFirstK(q,3);

    while(!q.empty()){
        int element=q.front();
        q.pop();
        cout<<element<<" ";
    }cout<<endl;
}