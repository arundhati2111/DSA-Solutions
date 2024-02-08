#include<iostream>
using namespace std;

void sumToN(int n){

    int sum=0;
    for(int i=1;i<=n;i++){
        sum=sum+i;
    }
    cout<<sum;
}
int main(){
    sumToN(5);
}