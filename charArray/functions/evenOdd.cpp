#include<iostream>
using namespace std;

void checkEvenOdd(int num){
    if(num%2==0){
        cout<<"Even";
    }
    else{
        cout<<"odd";
    }
}

int main(){
    checkEvenOdd(10);
}