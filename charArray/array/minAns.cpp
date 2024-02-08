#include<iostream>
#include<limits.h>
using namespace std;

int findMinimum(int arr[],int size){
    int minAns=INT_MAX;
    for(int i=0;i<size;i++){
        if(arr[i]<minAns){
            minAns=arr[i];
        }
    }
    return minAns;
    
}

int findMinimum2(int arr[],int size){
    int minAns=INT_MAX;
    for(int i=0;i<size;i++){
        minAns=min(arr[i],minAns);
    }
    return minAns;
    
}

int main(){
    int arr[6]={2,4,6,8,10,-12};
    int size=6;
    int minAns=findMinimum2(arr,size);
    cout<<minAns;
    
}