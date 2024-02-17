#include<iostream>
using namespace std;

void solve1(int* p){
    // by value
    p=p+1;
}

void solve2(int* &p){
    // by reference
    p=p+1;
}

int main(){
    int a=5;
    int* p=&a;
    
    cout<<"p "<<p<<endl;
    cout<<"*p "<<*p<<endl;
    cout<<"&p "<<&p<<endl;
    solve1(p);
    cout<<"p "<<p<<endl;
    cout<<"*p "<<*p<<endl;
    cout<<"&p "<<&p<<endl;
    solve2(p);
    cout<<"p "<<p<<endl;
    cout<<"*p "<<*p<<endl;
    cout<<"&p "<<&p<<endl;
}