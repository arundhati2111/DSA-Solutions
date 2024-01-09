#include<iostream>
using namespace std;

int firstOccurence(int arr[],int target,int n){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1; //element not found then -1 displayed
    while(s<=e){
        if(arr[mid]==target){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]<target){
            s=mid+1;
        }
        else if(arr[mid]>target){
            e=mid-1;
        }
        mid=s+(e-s)/2;

    }
    return ans;
}

int main(){
    int arr[]={10,20,30,30,30,30,40,50};
    int target=30;
    int n=8;
    int ans=firstOccurence(arr,target,n);
    cout<<ans<<endl;
}