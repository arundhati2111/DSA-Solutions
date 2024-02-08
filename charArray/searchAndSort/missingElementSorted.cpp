#include<iostream>
using namespace std;

int missingElement(int arr[],int n){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        int diff=arr[mid]-mid;
        if(diff == 1){
            s=mid+1;
        }
        else{
            ans=mid;
            e=mid-1;
        }
        mid=s+(e-s)/2;
        
    }
    if (ans+1==0){ //to handle last element
        return n+1;
    }
    return ans;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int n=8;
    int ans=missingElement(arr,n);
    cout<<ans<<endl;
}