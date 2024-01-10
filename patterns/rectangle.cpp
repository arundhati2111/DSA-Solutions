#include<iostream>
using namespace std;

int main(){
    int ROWS,COLS;
    cin>>ROWS;
    cin>>COLS;
    for(int row=0;row<ROWS;row++){
        for(int col=0;col<COLS;col++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}