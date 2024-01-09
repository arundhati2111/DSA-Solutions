#include<iostream>
using namespace std;

void sortZeroOne(int arr[],int size){
    // Step A: Count zero and one
    int zeroCount=0;
    int oneCount=0;
    for(int i=0;i<size;i++){
        if(arr[i]==0){
            zeroCount++;
        }
        if(arr[i]==1){
            oneCount++;
        }
    }
    // Step B: Place all Zero first
    int i;
    for(i=0;i<zeroCount;i++){
        arr[i]=0;
    }
    for(int j=i;j<size;j++){
        arr[j]=1;
    }

    // EASY WAY
    int index=0;
    while(zeroCount--){
        arr[index]=0;
        index++;
    }
    while(oneCount--){
        arr[index++]=1;
        index++;
    }

}

void sort2(int arr[],int n){
    int l=0;
    int h=n-1;
    while(l<h){
        while(arr[l]==0 && l<h){
            l++;
        }
        while(arr[h]==1 && l<h){
            h--;
        }
        swap(arr[l],arr[h]);
        l++;
        h--;
    }

    // USING IF ELSE
    while(l<h){
        if(arr[l]==0){
            l++;
        }
        else if(arr[h]==1){
            h++;
        }
        else{
            swap(arr[l],arr[h]);
        }
    }

}

int main(){
    int arr[]={0,0,0,1,1,0,1,0,1,0,1,0,1,1,1};
    int size=15;
    sortZeroOne(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}