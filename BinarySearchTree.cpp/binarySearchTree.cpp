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

void levelOderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }

        }
        else{
            cout<<temp->data<<" ";
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }

    }
}

void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    // NLR
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root==NULL){
        return;
    }
    // LNR
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root==NULL){
        return;
    }
    // LRN
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" "; 
}

int main(){
    Node* root=NULL;
    createBST(root);
    cout<<"Level Order Traversal: "<<endl;
    levelOderTraversal(root);
    cout<<endl;
    cout<<"Pre Order Traversal: "<<endl;
    preOrder(root);
    cout<<endl;
    cout<<"In Order Traversal: "<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"Post Order Traversal: "<<endl;
    postOrder(root);
}