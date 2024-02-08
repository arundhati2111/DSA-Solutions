#include<iostream>
using namespace std;

int paintPoles(int n,int k){
    if(n==1)
        return k;
    if(n==2)
        return k+ k*(k-1);
    int ans=(k-1)*(paintPoles(n-1,k)+paintPoles(n-2,k));
    return ans;
}

int main(){
    int n=3;
    int k=3;
    int ans = paintPoles(n,k);
    cout<<ans;
}