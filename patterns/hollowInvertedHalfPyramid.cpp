#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    // METHOD 1
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(row==0||col==0||col==n-row-1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
            
        }
        cout<<endl;
    }
    // METHOD 2
    for(int row=0;row<n;row++){
        for(int col=0;col<n-row;col++){
            if(row==0||row==n-1){
                cout<<"*";
            }
            else{
                if(col==0||col==n-row-1){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }
        }cout<<endl;
    }
}