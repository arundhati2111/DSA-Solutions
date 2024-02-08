#include<iostream>
#include<cmath>
using namespace std;

// DIVISION METHOD 
int decimalToBinaryMEthod1(int n){
    int binaryno=0;
    int i=0;
    while(n>0){
        int bit=n%2;
        binaryno=bit * pow(10,i++) + binaryno;
        n=n/2;
    }
    return binaryno;
}

// BITWISE METHOD 
int decimalToBinaryMEthod2(int n){
    int binaryno=0;
    int i=0;
    while(n>0){
        int bit=n&1;
        binaryno=bit * pow(10,i++) + binaryno;
        n=n>>1;
    }
    return binaryno;
}

int main(){
    int n;
    cin>>n;
    int binary=decimalToBinaryMEthod2(n);
    cout<<binary<<endl;
}