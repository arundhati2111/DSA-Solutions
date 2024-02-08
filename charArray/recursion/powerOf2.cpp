#include<iostream>
using namespace std;

int pow(int n){
    if(n==0){
        return 1;
    }
    int ans=2*pow(n-1);
    return ans;
}

int main(){
    int n;
    cin>>n;
    int ans=pow(n);
    cout<<ans<<endl;
}