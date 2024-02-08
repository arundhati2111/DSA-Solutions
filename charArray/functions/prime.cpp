#include<iostream>
using namespace std;

bool checkPrime(int n){
    for(int i=2;i<n;i++){
        if (n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    bool prime=checkPrime(7);
    if(prime){
        cout<<"It is a prime number";
    }
    else{
        cout<<"It is not a prime number";
    }
}