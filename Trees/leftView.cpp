#include<iostream>
#include<vector>
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

Node* createTree(){
    cout<<"Enter the value for node "<<endl;
    int value;
    cin>>value;

    if(value==-1){
        return NULL;
    }

    // create node
    Node* root=new Node(value);

    cout<<"Enter in left of "<<root->data<<endl;
    root->left=createTree();
    cout<<"Enter in right of "<<root->data<<endl;
    root->right=createTree();

    return root;
}


void printLeftView(Node* root,int level,vector<int> &leftView){
    if(root == NULL){
        return;
    }    

    if(leftView.size()==level){
        // left view node found
        leftView.push_back(root->data);
    }

    printLeftView(root->left,level+1,leftView);
    printLeftView(root->right,level+1,leftView);
}

int main(){
    Node* root= createTree();
    vector<int> leftView;
    printLeftView(root,0,leftView);
    for(int i=0;i<leftView.size();i++){
        cout<<leftView[i]<<endl;
    }
    return 0;
}
