#include<iostream>
using namespace std;

void rev(int n){
    if(n==1){
        cout<<1<<endl;
        return;
    }
    cout<<n<<" ";
    rev(n-1);
}

int main(){
    int n;
    cin>>n;
    rev(n);
}