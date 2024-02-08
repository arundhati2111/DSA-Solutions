#include<iostream>
using namespace std;

void sumEvenOdd(int n){

    int sum=0;
    for(int i=2;i<=n;i=i+2){
        sum=sum+i;
    }
    cout<<sum;
}
int main(){
    sumEvenOdd(5);
}