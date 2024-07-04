#include<iostream>
#include<queue>
using namespace std;


int main(){
    string str="ababc";
    queue<char> q;
    int freq[26]={0};

    for(int i=0;i<str.length();i++){
        char ch=str[i];
        freq[ch-'a']++;
        q.push(ch);

        // ans find
        while(!q.empty()){
            char frontCharacter=q.front();
            if(freq[frontCharacter-'a']>1){
                // this is not answer 
                q.pop();
            }
            else{
                // freq of front character is 1, there is no chance it can be zero because updated in line 13
                // this is the answer 
                cout<<frontCharacter<<" ";
                break;
            }
        }
        if(q.empty()){
            cout<<"#"<<" ";
        }
    }
}