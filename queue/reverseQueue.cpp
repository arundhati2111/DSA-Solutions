#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverse(queue<int> &q){
    stack<int> st;
    // put all elements from q to stack
    while(!q.empty()){
        int element=q.front();
        q.pop();
        st.push(element);
    }
    // put all elements from stack to queue 
    while(!st.empty()){
        int element=st.top();
        st.pop();
        q.push(element);
    }

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