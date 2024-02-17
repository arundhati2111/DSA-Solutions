#include<iostream>
#include<stack>
using namespace std;

int main(){
    int M[3][3];
    stack<int> st;

    // push all the elements in the stack
    for(int i=0;i<st.size();i++){
        st.push(i);
    }
    while(st.size()!=1){
        int a=st.top();st.pop();
        int b=st.top();st.pop();

        if(M[a][b]){
            // a is not a celebrity b might be
            st.push(b);
        }
        else{
            st.push(a);
        }
    }

    int mightBeCelebrity= st.top(); st.pop();

    for(int i=0;i<st.size();i++){
        if(M[mightBeCelebrity][i]!=0){
            return -1;
        }
        if(M[i][mightBeCelebrity] ==0 && i!=mightBeCelebrity){
            return -1;
        }
    }

    return mightBeCelebrity;
    
}