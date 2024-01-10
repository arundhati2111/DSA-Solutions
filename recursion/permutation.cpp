#include<iostream>
using namespace std;

void printPermutations(string str,int i){
    if(i>=str.length()){
        cout<<str<<" ";
        return;
    }
    for(int j=i;j<str.length();j++){
        swap(str[j],str[i]);
        printPermutations(str,i+1);
    }
}

void printPermutations2(string &str,int i){
    if(i>=str.length()){
        cout<<str<<" ";
        return;
    }
    for(int j=i;j<str.length();j++){
        swap(str[j],str[i]);
        printPermutations(str,i+1);
        // backtracking nullify action
        swap(str[i],str[j]);
    }
}

int main(){
    string str="abc";
    int i=0;
    printPermutations(str,i);
    cout<<endl;
    printPermutations2(str,i);
}