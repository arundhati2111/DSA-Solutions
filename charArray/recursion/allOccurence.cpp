#include<iostream>
using namespace std;

void searchIndex(int arr[],int size,int target,int index){
    if(index>=size){
        return;
    }
    if(arr[index]==target){
        cout<<index<<" ";
    }
    searchIndex(arr,size,target,index+1);
}

int main(){ 
    int arr[5]={10,20,10,10,50};
    int size=5;
    int index=0;
    int target=10;
    searchIndex(arr,size,target,index);

}