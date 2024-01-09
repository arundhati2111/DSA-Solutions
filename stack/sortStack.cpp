#include<iostream>
#include<stack>
using namespace std;

// insert the target in the right place in sorted stack
void insertSorted(stack<int> &s,int target){
    if(s.empty()){
        s.push(target);
        return;
    }
    if(s.top() >= target){
        s.push(target);
        return;
    }
    int topElement=s.top();
    s.pop();
    insertSorted(s,target); 

    // backtracking
    s.push(topElement);
}

// sort stack
void sortStack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int topElement=s.top();
    s.pop();
    sortStack(s);
    insertSorted(s,topElement);
}

int main(){
    stack<int> s;
    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);

    sortStack(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }cout<<endl;
}