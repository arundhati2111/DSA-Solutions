#include<iostream>
#include<vector>
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
    // cout<<"Recieved word "<<word<<" for insertion "<<endl;
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

// bool searchWord
bool searchWord(TrieNode* root,string word){
    if(word.length()==0){
        return root->isTerminal;
    }

    char ch=word[0];
    int index=ch-'a';
    TrieNode* child;

    if(root->children[index]!=NULL){
        // child is present or found
        child=root->children[index];
    }
    else{
        // not found
        return false;
    }
    // recursion
    bool recursionAns=searchWord(child,word.substr(1));
    return recursionAns;
}

void deleteWord(TrieNode* root,string word){
    if(word.length()==0){
        root->isTerminal=false;
        return;
    }

    char ch=word[0];
    int index=ch-'a';
    TrieNode* child;

    if(root->children[index]!=NULL){
        // present
        child=root->children[index]; //travel there

    }
    else{
        // not found
        return;
    }

    deleteWord(child,word.substr(1));
}

void storeString(TrieNode* root,vector<string> &ans,string &input,string &prefix){
    if(root->isTerminal==true){
        ans.push_back(prefix+input);
    }
    for(char ch='a';ch<='z';ch++){
        int index=ch-'a';
        TrieNode* next=root->children[index];
        if(next!=NULL){
            // child exists
            input.push_back(ch);
            // recursion
            storeString(next,ans,input,prefix);
            // backtrack
            input.pop_back();
        }
    }
}

void findPrefixString(TrieNode* root,string input,vector<string> &ans,string &prefix){
    if(input.length()==0){
        TrieNode* lastChar=root; 
        storeString(lastChar,ans,input,prefix);
        return;
    }
    char ch=input[0];
    int index=ch-'a';
    TrieNode* child;
    if(root->children[index] != NULL){
        // child present
        child=root->children[index];
    }
    else{
        return;
    }
    // recursive call
    findPrefixString(child,input.substr(1),ans,prefix);
}

vector<vector<string>> getSuggestions(TrieNode* root,string input){
    vector<vector<string>> output;
    TrieNode* prev=root;
    string prefix="";

    for(int i=0;i<input.length();i++){
        char lastChar=input[i];
        int index=lastChar-'a';
        TrieNode* curr=prev->children[index];

        if(curr==NULL){
            break;
        }

        else{
            vector<string> nicheKaAns;
            prefix.push_back(lastChar);
            string dummy="";
            storeString(curr,nicheKaAns,prefix,dummy);
            output.push_back(nicheKaAns);
            prev=curr; 
        }
    }
    return output;
}

int main(){
    TrieNode* root=new TrieNode('-');
    insertWord(root,"cater");
    insertWord(root,"care");
    insertWord(root,"com");
    insertWord(root,"lover");
    insertWord(root,"loved");
    insertWord(root,"load");
    insertWord(root,"lov");
    insertWord(root,"bat");
    insertWord(root,"cat");
    insertWord(root,"car");

    vector<vector<string>> ans= getSuggestions(root,"loa");

    for(int i=0;i<ans.size();i++){
        cout<<i<<" ";
        for(auto str:ans[i]){
            cout<<str<<", ";
        }cout<<endl;
         
    }
    
}