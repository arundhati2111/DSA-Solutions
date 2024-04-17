#include<iostream>
#include<string>
#include<vector>
using namespace std;

// function overloading
int add(int a, int b){
    return a+b;
}

double add(double a,double b){
    return a+b;
}

int add(int a, int b,int c){
    return a+b+c;
}

int main(){
    cout<<add(3,4)<<endl;
    cout<<add(3.6,7.8)<<endl;
    cout<<add(55,23,78)<<endl;
}