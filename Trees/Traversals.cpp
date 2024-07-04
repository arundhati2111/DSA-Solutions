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


void preOrderTraversal(Node* root){
    // base case
    if(root==NULL){
        return;
    }

    // NLR
    // N
    cout<<root->data<<" ";
    // L
    preOrderTraversal(root->left);
    // R
    preOrderTraversal(root->right);

}

void inOrderTraversal(Node* root){
    // base case
    if(root==NULL){
        return;
    }

    // LNR
    // L
    inOrderTraversal(root->left);
    // N
    cout<<root->data<<" ";    
    // R
    inOrderTraversal(root->right);

}

void postOrderTraversal(Node* root){
    // base case
    if(root==NULL){
        return;
    }

    // LRN
    // L
    postOrderTraversal(root->left);    
    // R
    postOrderTraversal(root->right);
    // N
    cout<<root->data<<" ";    

}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    // traversal
    // FIRST WHILE CONDITION
    // while(q.size()>1){
    //     Node* front=q.front();
    //     q.pop();

    //     if(front==NULL){
    //         cout<<endl;
    //         q.push(NULL);
    //     }

    //     else{
    //         cout<<front->data<<" ";

    //         if(front->left != NULL){
    //             q.push(front->left);
    //         }
    //         if(front->right != NULL){
    //             q.push(front->right);
    //         }
    //     }

        
    // }

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


int main(){
    Node* root= createTree();
    cout<<"Printing PreOrder"<<endl;
    preOrderTraversal(root);
    cout<<endl;

    cout<<"Printing InOrder"<<endl;
    inOrderTraversal(root);
    cout<<endl;

    cout<<"Printing PostOrder"<<endl;
    postOrderTraversal(root);
    cout<<endl;

    cout<<"Printing LevelOrder"<<endl;
    levelOrderTraversal(root);
    cout<<endl;

}
