#include<iostream>
using namespace std;

int searchNearlySorted(int arr[],int n,int target){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;

    while(s<=e){
        if(mid-1>=0 && arr[mid-1]==target){
            return mid-1;
        }
        if(arr[mid]==target){
            return mid;
        }
        if(mid+1 <n && arr[mid+1]==target){
            return mid+1;
        }
        if(arr[mid]<target){
            s=mid+2;
        }
        else{
            e=mid-2;
        }
        mid=s+(e-s)/2;
    }
    return -1; 

}

int main(){
    int arr[]={20,10,30,50,40,70,60};
    int n=7;
    int target=60;

    int index=searchNearlySorted(arr,n,target);

    if(index == -1){
        cout<<"Element is not present in the array";
    }
    else{
        cout<<"Element is present in the array at index "<<index<<endl;
    }
}