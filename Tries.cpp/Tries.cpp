#include<iostream>
using namespace std;

class TrieNode{
    public:
        char value;
        TrieNode* children[26]; //dynamic array
        bool isTerminal; 

        TrieNode(char val){
            this->value=val;
            for(int i=0;i<26;i++){
                children[i]= NULL;
            }
            this->isTerminal=false;
        }
};

void insertWord(TrieNode* root,string word){
    cout<<"Recieved word "<<word<<" for insertion "<<endl;
    // base case
    if(word.length()==0){
        // reached terminal 
        root->isTerminal=true;
        return;
    }
    char ch=word[0];
    int index=ch-'a';
    TrieNode* child;
    if(root->children[index]!=NULL){
        child=root->children[index];
    }
    else{
        child=new TrieNode(ch);
        root->children[index]=child; 
    }

    // recursion
    insertWord(child,word.substr(1));
}

int main(){
    TrieNode* root=new TrieNode('-');
    insertWord(root,"donation");
    insertWord(root,"dona");
}