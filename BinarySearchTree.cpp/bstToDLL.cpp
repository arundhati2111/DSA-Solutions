#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data=val;
            this->left=NULL;
            this->right=NULL;
        }
};

Node* bstInorder(int inorder[],int s,int e){
    // base case
    if(s>e){
        return NULL;
    }

    int mid=(s+e)/2;
    int element=inorder[mid];
    Node* root=new Node(element);

    root->left=bstInorder(inorder,s,mid-1);
    root->right=bstInorder(inorder,mid+1,e);

    return root;
}

void bstToDLL(Node* root,Node* &head){
    if(root==NULL){
        return;
    }
    // RNL
    // R
    bstToDLL(root->right,head);
    // N
    root->right=head;
    if(head!=NULL)
        head->left=root;
    head=root;
    // L
    bstToDLL(root->left,head);
}

void printingLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
    cout<<endl;
}

int main(){
    int inorder[]={10,20,30,40,50,60,70};
    int size=7;
    int start=0;
    int end=size-1;
    Node* root=bstInorder(inorder,start,end);
    Node* head=NULL;
    bstToDLL(root,head);
    printingLL(head);
}