#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> dq;
    dq.push_front(5);
    dq.push_front(10);
    dq.push_back(20);
    dq.push_back(30);

    dq.pop_front();
    dq.pop_back();

    cout<<dq.front();
    cout<<dq.back();
}