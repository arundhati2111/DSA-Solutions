#include<iostream>
#include<limits.h>
using namespace std;

void maxArray(int arr[],int size,int &maxi,int index){
    if(index>=size){
        return ;
    }
    maxi=max(maxi,arr[index]);

    maxArray(arr,size,maxi,index+1);    
}

int main(){ 
    int arr[5]={20,30,10,5,11};
    int size=5;
    int index=0;
    int maxi=INT_MIN;
    maxArray(arr,size,maxi,index);
    cout<<"Maxmum element in the array is: "<<maxi;
    
}
