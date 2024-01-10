#include<iostream>
using namespace std;

int binarySearch(int arr[],int target,int n){
    int start=0;
    int end=n-1;
    int mid=(start+end)/2; //FAULT IN THIS CASE
    while(start<=end){
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            end=mid-1;
        }
        else if(arr[mid]<target){
            start=mid+1;
        }
        mid=(start+end)/2; 
    }
    // element not found
    return -1; //invalid index can be any value

}

int main(){
    int arr[]={10,20,30,40,50,60,70,80,90};
    int target=90;
    int n=9;

    int ans=binarySearch(arr,target,n);

    if(ans==-1){
        cout<<"Element not found"<<endl;
    }
    else{
        cout<< "Element is present at index "<<ans << endl;
    }
}