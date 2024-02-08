#include<iostream>
using namespace std;

void quickSort(int arr[],int s,int e){
    if(s>=e) return;
    int pivot=e;
    int i=s-1;
    int j=s;
    while(j<pivot){
        if(arr[j]<arr[pivot]){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    i++; 
    swap(arr[i],arr[pivot]);
    quickSort(arr,s,i-1);
    quickSort(arr,i+1,e);
}
int main(){
    int arr[]={7,2,1,8,6,3,5,4};
    int n=8;
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

