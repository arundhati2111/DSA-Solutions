#include<iostream>
#include<limits.h>
using namespace std;

void minArray(int arr[],int size,int &mini,int index){
    if(index>=size){
        return ;
    }
    mini=min(mini,arr[index]);

    minArray(arr,size,mini,index+1);    
}

int main(){ 
    int arr[5]={20,30,10,5,11};
    int size=5;
    int index=0;
    int mini=INT_MAX;
    minArray(arr,size,mini,index);
    cout<<"Minimum element in the array is: "<<mini;
    
}
