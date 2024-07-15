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

Node* minValue(Node* root){
    if(root==NULL){
        // cout<<"No minimum value exists"<<endl;
        return NULL;
    }
    Node* temp=root;

    while(temp->left !=NULL){
        temp=temp->left;
    }
    return temp;
}

Node* maxValue(Node* root){
    if(root==NULL){
        return NULL;
    }

    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

int main(){
    Node* root=NULL;
    createBST(root);
    cout<<"Level Order Traversal: "<<endl;
    levelOderTraversal(root);
    cout<<endl;
    
    Node* minNode=minValue(root);
    if(minNode == NULL){
        cout<<"Tree is empty hence no minimum element exists"<<endl;
    }
    else{
        cout<<"Minimum node is: "<<minNode->data<<endl;
    }

    Node* maxNode=maxValue(root);
    if(maxNode == NULL){
        cout<<"Tree is empty hence no maximum element exists"<<endl;
    }
    else{
        cout<<"Maximum node is: "<<maxNode->data<<endl;
    }
}