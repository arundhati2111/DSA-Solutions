#include<iostream>
#include<queue>
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

Node* insertIntoBST(Node* root,int data){
    if(root==NULL){
        root=new Node(data); //create a new node with the data passed 
        return root;
    }
    
    // not the first node so will decide whether to go on right side or left side
    if(data>root->data){
        // go to right
        root->right=insertIntoBST(root->right,data);
    }
    else{
        root->left=insertIntoBST(root->left,data);
    }
    return root;

}

void createBST(Node* &root){
    cout<<"Enter data "<<endl;
    int data;
    cin>>data;

    while(data!=-1){
        root=insertIntoBST(root,data);
        cout<<"Enter data"<<endl;
        cin>>data;
    }
}

bool searchBST(Node* root,int target){
    if(root==NULL){
        return false;
    }
    if(root->data==target){
        return true;
    }
    bool leftAns=false;
    bool rightAns=false;
    if(target>root->data){
        rightAns=searchBST(root->right,target);
    }
    else{
        leftAns=searchBST(root->left,target);
    }

    return leftAns || rightAns;
}

int main(){
    Node* root=NULL;
    createBST(root);
    cout<<"Enter target: ";
    int target;
    cin>>target;

    while(target!=-1){
        bool ans=searchBST(root,target);
        if(ans==true){
            cout<<"Found"<<endl;
        }
        else{
            cout<<"Not Found"<<endl;
        }
        cout<<"Enter target: ";
        cin>>target;
    }
}