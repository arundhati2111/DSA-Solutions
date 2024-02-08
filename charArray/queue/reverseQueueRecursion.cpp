#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverse(queue<int> &q){

    if(q.empty()){
        return;
    }

    int t=q.front();
    q.pop();
    reverse(q);
    q.push(t);
}

int main(){
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    reverse(q);

    cout<<"Printing"<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }cout<<endl;
}