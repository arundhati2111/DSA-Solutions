// #include<iostream>
// #include<stack>
// using namespace std;

// void solve(stack<int> &s,int target){
//     if(s.empty()){
//         s.push(target);
//         return;
//     }
//     int topElement=s.top();
//     s.pop();
//     solve(s,target);
//     // backtrack
//     s.push(topElement);
// }

// void insertAtBottom(stack<int> &s){
//     if(s.empty()){
//         cout<<"Stack is empty,can't insert at bottom"<<endl;
//         return;
//     }
//     int target=s.top();
//     s.pop();
//     solve(s,target);
// }

// int main(){
//     stack<int> s;

//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     s.push(50);

//     insertAtBottom(s);

//     cout<<"Printing"<<endl;
//     while(!s.empty()){
//         cout<<s.top()<<" ";
//         s.pop();
//     }cout<<endl;
// }


// WAY 2 
#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s,int target){
    if(s.empty()){
        s.push(target);
        return;
    }
    int topElement=s.top();
    s.pop();
    insertAtBottom(s,target);
    // backtrack
    s.push(topElement);
}


int main(){
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    if(s.empty()){
        cout<<"Stack is empty,can't insert at bottom"<<endl;
        return 0;
    }
    int target=s.top();
    s.pop();

    insertAtBottom(s,target);

    cout<<"Printing"<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }cout<<endl;
}