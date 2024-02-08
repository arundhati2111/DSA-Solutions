#include<iostream>
using namespace std;

void printArray(int arr[],int size,int index){
    if(index>=size){
        return;
    }
    cout<<arr[index]<<" ";
    printArray(arr,size,index+1);
}

int main(){
    int arr[5]={10,20,30,40,50};
    int size=5;
    int index=0;
    printArray(arr,size,index);
}