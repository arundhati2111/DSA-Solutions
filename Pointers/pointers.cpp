#include<iostream>
using namespace std;

void solve(int *arr,int size){
    cout<<"Size of array inside function is: "<<sizeof(arr)<<endl; //size of pointer 
    cout<<"Inside function: "<<endl;
    cout<<"arr "<<arr<<endl; //base address
    cout<<"&arr "<<&arr<<endl; //address of pointer memory block
}

int main(){
    int arr[]={10,20,30,40,50};
    cout<<"Size of array: "<<sizeof(arr)<<endl; //size of array 
    solve(arr,5);
    cout<<"arr "<<arr<<endl; //base address
    cout<<"&arr "<<&arr<<endl; //base address
    return 0;
}