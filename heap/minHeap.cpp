#include<iostream>
#include<queue>
using namespace std;

int main(){
    // min heap creation 
    priority_queue<int,vector<int>,greater<int>> pq;

    // insert
    pq.push(100);
    pq.push(90);
    pq.push(70);

    cout<<"Top element is "<<pq.top()<<endl;

    pq.pop();
    
    cout<<"Top element is "<<pq.top()<<endl;

    cout<<"size of min heap"<<pq.size()<<endl;

    if(pq.empty()){
        cout<<"Min heap is empty"<<endl;
    }
    else{
        cout<<"Min heap is not empty"<<endl;
    }

    return 0;
}