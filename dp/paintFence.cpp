#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecursion(int n,int k){
    // base case
    if(n==1){
        return k;
    }
    if(n==2){
        return (k+k*(k-1));
    }

    int ans=(solveUsingRecursion(n-1,k)+solveUsingRecursion(n-2,k))*(k-1);
    return ans;
}

int solveUsingMemo(int n,int k,vector<int> &dp){
    // base case
    if(n==1){
        return k;
    }
    if(n==2){
        return (k+k*(k-1));
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n]=(solveUsingMemo(n-1,k,dp)+solveUsingMemo(n-2,k,dp))*(k-1);
    return dp[n];
}

int solveUsingTabulation(int n,int k){
    vector<int> dp(n+1,-1);

    dp[1]=k;
    dp[2]=k+k*(k-1);

    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])*(k-1);
    }

    return dp[n];
}

int solveUsingTabulationSO(int n,int k){
    int prev2=k;
    int prev1=k+k*(k-1);
    if(n==1){
        return prev2;
    }
    if(n==2){
        return prev1;  
    }
    int curr;
    for(int i=3;i<=n;i++){
        curr=(prev1+prev2)*(k-1);
        // shft
        prev2=prev1;
        prev1=curr;
    }

    return prev1;
}

int main(){
    int n=3;
    int k=3;

    // // // int ans=solveUsingRecursion(n,k);
    // // // cout<<"Ans: "<<ans<<endl;

    // // vector<int> dp(n+1,-1);

    // // int ans=solveUsingMemo(n,k,dp);
    // int ans=solveUsingTabulation(n,k);
    int ans=solveUsingTabulationSO(n,k);
    cout<<"Ans "<<ans<<endl;


}