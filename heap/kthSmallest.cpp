#include<iostream>
#include<queue>
using namespace std;

int getKthSmallestElement(int arr[],int n,int k){
    priority_queue<int> pq;
    // process first k elements 
    for(int i=0;i<k;i++){
        int element=arr[i];
        pq.push(element);
    }
    // insert remaining elements only when smaller thn root
    for(int i=k;i<n;i++){
        int element=arr[i];
        if(element<pq.top()){
            pq.pop();
            pq.push(element);
        }

    }
    int ans=pq.top();
    return ans;
}

int main(){
    int arr[]={3,5,4,6,9,8,7};
    int n=7;
    int k=4;
    cout<<"4th smallest number is "<<getKthSmallestElement(arr,n,k);
}