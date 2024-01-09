#include<iostream>
using namespace std;

void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

void extremePrint(int arr[],int size){
    int left=0;
    int right=size-1;
    while(left<=right){ //left<=right
        if(left==right){
            cout<<arr[left];
        }
        else{
            cout<<arr[left]<<" ";
        cout<<arr[right]<<" ";
        }
        
        left++;
        right--;
    }
    
}

int main(){
    int arr[5]={2,4,6,8,10};
    int size=5; 
    extremePrint(arr,size);
}