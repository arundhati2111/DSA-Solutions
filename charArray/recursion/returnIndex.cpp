#include<iostream>
using namespace std;

int searchIndex(int arr[],int size,int target,int index){
    if(index>=size){
        return -1;
    }
    if(arr[index]==target){
        return index;
    }
    searchIndex(arr,size,target,index+1);
}

int main(){ 
    int arr[5]={10,20,30,40,50};
    int size=5;
    int index=0;
    int target=50;
    int ans=searchIndex(arr,size,target,index);
    if(ans==-1){
        cout<<"Element not found";
    }
    else{
        cout<<"Element found at index "<<ans;
    }

}