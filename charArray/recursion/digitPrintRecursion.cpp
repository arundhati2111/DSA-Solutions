#include<iostream>
using namespace std;

void digPrint(int n){
    if(n==0){
        return;
    }
    int r=n%10;
    int q=n/10;
    digPrint(q);
    cout<<r<<" ";
}

int main(){ 
    int n;
    cin>>n;
    digPrint(n);

}