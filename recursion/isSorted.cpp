#include<iostream>
using namespace std;

bool isSorted(int arr[],int size,int index){
    if (index>=size){
        return true;
    }
    if(arr[index]>arr[index-1]){
        bool aageKaAns=isSorted(arr,size,index+1);
        return aageKaAns;
    }
    else{
        return false;
    }
}

int main(){
    int arr[]={10,20,30,40,50};
    int size=5;
    int index=1;
    bool ans=isSorted(arr,size,index);
    if(ans){
        cout<<"sorted"<<endl;
    }
    else{
        cout<<"Not sorted"<<endl;
    }
}