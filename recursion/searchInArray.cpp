#include<iostream>
using namespace std;

bool searchArray(int arr[],int size,int target,int index){
    if(index>=size){
        return true;
    }
    if(arr[index]==target){
        return true;
    }
    searchArray(arr,size,target,index+1);
}

int main(){ 
    int arr[5]={10,20,30,40,50};
    int size=5;
    int index=0;
    int target=50;
    // bool ans=searchArray(arr,size,target,index);
    // if(ans){
    //     cout<<"Ans found"<<endl;
    // }
    // else{
    //     cout<<"Ans not found"<<endl;
    // }
    cout<<"Target found or not:"<<searchArray(arr,size,target,index);
}