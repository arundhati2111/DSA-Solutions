#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> dq;
    dq.push_back(10);
    cout<<"Front element "<<dq.front()<<endl;
    cout<<"Back element "<<dq.back()<<endl;
    cout<<"Size of doubly ended queue "<<dq.size()<<endl;

    dq.push_front(20);
    cout<<"Front element "<<dq.front()<<endl;
    cout<<"Back element "<<dq.back()<<endl;
    cout<<"Size of doubly ended queue "<<dq.size()<<endl;

    dq.pop_back();
    cout<<"Front element "<<dq.front()<<endl;
    cout<<"Back element "<<dq.back()<<endl;
    cout<<"Size of doubly ended queue "<<dq.size()<<endl;
}