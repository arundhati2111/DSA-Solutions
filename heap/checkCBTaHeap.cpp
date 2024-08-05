#include<iostream>
using namespace std;

// class to create a pair
class Info{
    public:
        int maxVal;
        bool isHeap;
        Info(){}
        Info(int a,bool b){
            this->maxVal=a;
            this->isHeap=b;
        }
};

class Node{
    public:
        int data;
        Node* right;
        Node* left;

        Node(int val){
            this->data=val;
            this->left=NULL;
            this->right=NULL;
        }
};

Info checkMaxHeap(Node* root){
    if(root==NULL){
        Info temp;
        temp.maxVal=INT16_MIN;
        temp.isHeap=true;
        return temp;
    }
    if(root->left==NULL && root->right==NULL){
        // leaf node 
        Info temp;
        temp.maxVal=root->data;
        temp.isHeap=true;
    }
    Info leftAns=checkMaxHeap(root->left);
    Info rightAns=checkMaxHeap(root->right);
    

    if(root->data>leftAns.maxVal && root->data> rightAns.maxVal && leftAns.isHeap && rightAns.isHeap){
        Info ans;
        ans.maxVal=root->data;
        ans.isHeap=true;
        return ans;
    }
    else{
        Info ans;
        ans.maxVal=max(root->data,max(leftAns.maxVal,rightAns.maxVal));
        ans.isHeap=false;
        return ans;
    }
}

// pair<int,bool> 

int main(){

}