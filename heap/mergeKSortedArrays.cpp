#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Info{
    public:
        int data;
        int rowIndex;
        int colIndex;

        Info(int val,int row,int col){
            this->data=val;
            this->rowIndex=row;
            this->colIndex=col;
        }
};

class compare{
    public:
        bool operator()(Info* a,Info* b){
            return a->data > b->data;
        }
};

void mergeKSortedArray(int arr[][4],int n,int k,vector<int> &ans){
    priority_queue<Info*,vector<Info*>,compare> pq;

    // process first k elements
    for(int row=0;row<k;row++){
        int element=arr[row][0];
        Info* temp=new Info(element,row,0);
        pq.push(temp);
    }

    while(!pq.empty()){
        Info* temp=pq.top();
        pq.pop();
        int topData=temp->data;
        int topRow=temp->rowIndex;
        int topCol=temp->colIndex;

        // store in ans
        ans.push_back(topData);

        // next elt for the same row from where we have just popped elt needs to be inserted
        if(topCol+1 < n){
            // elements are present in row
            Info* newInfo= new Info(arr[topRow][topCol+1],topRow,topCol+1);
            pq.push(newInfo);
        }

    }
}

int main(){
    vector<int> ans;
    int arr[3][4]={
        {1,4,8,11},
        {2,3,6,10},
        {5,7,12,14}
    };
    int n=4;
    int k=3;

    mergeKSortedArray(arr,n,k,ans);

    cout<<"Printing array"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    
}