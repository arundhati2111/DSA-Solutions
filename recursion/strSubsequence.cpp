#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void subsequence(string str,string output,int index){
    // base case
    if(index>=str.length()){ 
        // ans is build in output string
        cout<<"->"<<output<<endl;
        return;
    }
    char ch=str[index];
    // exclude
    subsequence(str,output,index+1);
    // include
    output.push_back(ch);
    subsequence(str,output,index+1);
    
}

void subsequence2(string str,string output,int index,vector<string> &ans){
    // base case
    if(index>=str.length()){ 
        // ans is build in output string
        ans.push_back(output);
        return;
    }
    char ch=str[index];
    // exclude
    subsequence2(str,output,index+1,ans);
    // include
    output.push_back(ch);
    subsequence2(str,output,index+1,ans);
    
}

void subsequence3(string s){
    int num_sub=pow(2,s.size());
    for(int n=0;n<num_sub;++n){
        string output;
        int num=n;
        int i=0;
        while(num){
            int bit=num&1;
            if(bit){
                output.push_back(s[i]);
            }
            ++i;
            num>>=1;
        }
        cout<<"=>"<<output<<endl;
    }

}

int main(){
    string str="abc";
    vector<string> ans;
    // subsequence(str,"",0);
    // subsequence2(str,"",0,ans);
    subsequence3(str);
    // for(string str:ans){
    //     cout<<"=>"<<str<<endl;
    // }
}