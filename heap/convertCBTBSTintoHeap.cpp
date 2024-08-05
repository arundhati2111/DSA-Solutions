#include<iostream>
#include<vector>
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

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    // SECOND WHILE CONDITION
    while(!q.empty()){
        Node* front=q.front();
        q.pop();

        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
            
        }

        else{
            cout<<front->data<<" ";

            if(front->left != NULL){
                q.push(front->left);
            }
            if(front->right != NULL){
                q.push(front->right);
            }
        }

        
    }
}

void storeInordedr(Node* root,vector<int> &in){
    if(root==NULL){
        return;
    }
    // LNR
    storeInordedr(root->left,in);
    in.push_back(root->data);
    storeInordedr(root->right,in);
}

void replaceUsingPostorder(Node* root,vector<int> in,int &index){
    if(root==NULL){
        return;
    }
    // LRN
    replaceUsingPostorder(root->left,in,index);
    replaceUsingPostorder(root->right,in,index);
    root->data=in[index];
    index++;
}

Node* convertBstToHeap(Node* root){
    // create inorder
    vector<int> inorder;
    storeInordedr(root,inorder);
    // replace the values with inorder sorted values in post order
    int index=0;
    replaceUsingPostorder(root,inorder,index);
    return root;
}

int main(){
    Node* root=NULL;
    createBST(root);
    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"Conversion to Heap"<<endl;
    root=convertBstToHeap(root);
    levelOrderTraversal(root);
}