#include<iostream>
#include<deque>
using namespace std;

void solve(int arr[],int n,int k){
    deque<int> q;
    // first window processing
    for(int i=0;i<k;i++){
        if(arr[i]<0){
            q.push_back(i);
        }
    }
    // remaining window process
    for(int i=k;i<n;i++){
        // prev window ans
        if(q.empty()){
            cout<<0<<" ";
        }
        else{
            cout<<arr[q.front()]<<" ";
        }
        // out of window elt remove
        if(!q.empty() && (i-q.front()>=k)){
            q.pop_front();
        }
        // check current element for insertion
        if(arr[i]<0){
            q.push_back(i);
        }

    }
    if(q.empty()){
            cout<<0<<" ";
        }
        else{
            cout<<arr[q.front()]<<" ";
        }

}

int main(){
    int arr[]={12,-1,-7,8,-15,30,16,28};
    int size=8;
    int k=3;
    solve(arr,size,k);
}