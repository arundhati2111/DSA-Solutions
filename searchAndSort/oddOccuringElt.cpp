#include<iostream>
using namespace std;

int oddOccuringElt(int arr[],int n){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        // single elt
        if(s==e){
            return s;
        }
        // mid is on odd index
        if(mid&1){
            if(mid-1>=0 && arr[mid]==arr[mid-1]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        else{
            if(mid+1<n && arr[mid]==arr[mid+1]){
                s=mid+2;
            }
            else{
                e=mid;
            }
        }
        mid=s+(e-s)/2; 
    }
    return -1;
}

int main(){
    int arr[]={10,10,2,2,3,3,2,5,5,6,6,7,7};
    int n=13;
    int ansIndex=oddOccuringElt(arr,n);
    cout<<"Odd occuring elt is "<<arr[ansIndex]<<endl;

}