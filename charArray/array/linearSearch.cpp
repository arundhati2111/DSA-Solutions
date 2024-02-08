#include<iostream>
using namespace std;

bool linearSearch(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            return true;
        }
    }
    return false; 
}

int main(){
    int arr[6]={2,4,6,8,10,12};
    int target=10;
    int n=5;
    // bool flag=0;
    // for(int i=0;i<n;i++){
    //     if(arr[i]==target){
    //         flag=1;            
    //         break;
    //     }         
    // }
    // if(flag==1){
    //     cout<<"Target found"<<endl;
    // }
    // else{
    //     cout<<"Target not found"<<endl;
    // }
    bool ans=linearSearch(arr,n,target);
    if(ans){
        cout<<"Target found";
    }
    else{
        cout<<"Traget not found";
    }
    
}