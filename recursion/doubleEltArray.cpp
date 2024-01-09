#include<iostream>
using namespace std;

void doubleElt(int arr[],int size,int index){
    if(index>=size){
        return ;
    }
    arr[index]=arr[index]*2;

    doubleElt(arr,size,index+1);    
}

int main(){ 
    int arr[5]={20,30,10,5,11};
    int size=5;
    int index=0;
    doubleElt(arr,size,index);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
