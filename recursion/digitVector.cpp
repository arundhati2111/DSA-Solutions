#include<iostream>
#include<vector>
using namespace std;

void digPrint(int num,vector<int> &ans){
    if(num==0){
        return;
    }
    int digit=num%10;
    num=num/10;
    digPrint(num,ans);
    ans.push_back(digit);
}

int main(){ 
    int n;
    cin>>n;
    vector<int> ans;
    digPrint(n,ans);
    for(int num:ans){
        cout<<num<<" ";
    }

}