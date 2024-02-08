#include<iostream>
using namespace std;

void shift(int arr[],int size,int k){
    int temp[k];
    for(int i=0;i<k;i++){
        temp[i]=arr[size-k+i];

    }
    
    for(int i=size-1;i>=k;i--){
        arr[i]=arr[i-k];
    }
    for(int i=0;i<k;i++){
        arr[i]=temp[i];        
    }
    
}

int main(){
    int arr[]={10,20,30,40,50};
    int size=5;
    int k=2;
    shift(arr,size,k);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}