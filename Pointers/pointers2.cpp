#include<iostream>
using namespace std;

void solve(int *arr,int size){
    *arr=*arr+1;
}

int main(){
    int arr[]={10,20,30};
    cout<<"Before function call"<<endl;
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";
    }
    solve(arr,3);
    cout<<endl;
    cout<<"After function call"<<endl;
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}