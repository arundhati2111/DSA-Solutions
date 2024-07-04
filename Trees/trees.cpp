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

// it returns root node of the created tree
Node* createTree(){
    cout<<"Enter the value for node "<<endl;
    int data;
    cin>>data;

    if(data==-1){
        return NULL;
    }

    // create node
    Node* root=new Node(data);
    // create left subtree
    cout<<"Left of node "<<root->data<<endl;
    root->left= createTree();
    // create right subtree
    cout<<"Right of node "<<root->data<<endl;
    root->right=createTree();

    return root;
            

}


int main(){
    Node* root= createTree();
}