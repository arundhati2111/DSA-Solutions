#include<iostream>
using namespace std;

int binarySearch(int arr[],int start,int end,int target){
    if(start>=end){
        return -1;
    }
    int mid=start+(end-start)/2;
    if(arr[mid]==target){
        return mid;
    }
    if(arr[mid]<target){
        return binarySearch(arr,mid+1,end,target);
    }
    else{
        return binarySearch(arr,start,mid-1,target);
    }
}

int main(){
    int arr[]={10,20,30,40,50};
    int start=0;
    int n=5;
    int end=n-1;
    int target=70;
    int ans=binarySearch(arr,start,end,target);
    cout<<ans;
}