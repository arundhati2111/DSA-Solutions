#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

int main(){
    string s;
    stack<char> st;
    if(s.size()&1){
        return 0;
    }
    int ans=0;
    for(auto ch:s){
        if(ch=='{'){
            st.push(ch);
        }
        else{
            if(!st.empty() && st.top()=='{'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }
    while(!st.empty()){
        char a=st.top();
        st.pop();
        char b=st.top();
        st.pop();
        if(a==b){
            ans+=1;
        }
        else{
            ans+=2;
        }
    }
}