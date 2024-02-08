#include<iostream>
using namespace std;

int sumOfN(int n){
    if(n==1){
        return 1;
    }
    int ans=n+sumOfN(n-1);
    return ans;
}

int main(){
    int n;
    cin>>n;
    int ans=sumOfN(n);
    cout<<ans<<endl;
}