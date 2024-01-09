#include<iostream>
#include<stack>
using namespace std;

bool checkRedundant(string &str){
    stack<char> st;

    for(int i=0;i<str.length();i++){
        char ch=str[i];

        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            st.push(ch);
        }
        else if(ch==')'){
            // count operators between the OB & CB
            int operatorCount=0;
            while(!st.empty() && st.top()!='('){
                char temp=st.top();
                if(temp =='+' || temp =='-' || temp =='*' || temp =='/'){
                    operatorCount++;
                }
                st.pop();
            }
            // yaha phonche that means hmara OB is present in stack 
            st.pop();

            if(operatorCount==0){
                return true;
            }
        }
    }
    // hrr ek bracket ke beech mein operator pkka mila hoga tbhi yaha pohoncha
    return false;
}

int main(){
    string str="(((a+b)*(c+d)))";
    bool ans=checkRedundant(str);

    if(ans){
        cout<<"Redundant Brackets Present"<<endl;
    }
    else{
        cout<<"Redundant Brackets not Present"<<endl;
    }
}