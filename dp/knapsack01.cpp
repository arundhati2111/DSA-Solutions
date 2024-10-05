#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecursion(int capacity,int wt[],int profit[],int index,int n){
    // base case
    // if(index==n-1){
    //     // last element 
    //     if(wt[index]<=capacity){
    //         // include
    //         return profit[index];
    //     }
    //     else{
    //         return 0;
    //     }
    // }
    if(index>=n){
        return 0;
        // out of bound
    }

    // inc/exc
    int include=0;
    int exclude=0;
    if(wt[index]<=capacity){
        include=profit[index]+solveUsingRecursion(capacity-wt[index],wt,profit,index+1,n);
    }
         
    exclude=0+solveUsingRecursion(capacity,wt,profit,index+1,n);

    int ans=max(include,exclude);
    return ans;

}

int solveUsingMemo(int capacity,int wt[],int profit[],int index,int n,vector<vector<int>> &dp){
    if(index>=n){
        return 0;
        // out of bound
    }

    if(dp[capacity][index] != -1){
        return dp[capacity][index];
    }

    // inc/exc
    int include=0;
    int exclude=0;
    if(wt[index]<=capacity){
        include=profit[index]+solveUsingMemo(capacity-wt[index],wt,profit,index+1,n,dp);
    }
         
    exclude=0+solveUsingMemo(capacity,wt,profit,index+1,n,dp);

    dp[capacity][index]=max(include,exclude);
    return dp[capacity][index];
}

// void printDp(vector<vector<int>> &dp){
//     for(int i=0;i<dp.size();i++){
//         for(int j=0;j<dp[0].size();j++){
//             cout<<dp[i][j]<<" ";
//         }cout<<endl;
//     }cout<<endl;
// }

int solveUsingTabulation(int capacity,int wt[], int profit[],int n){
    vector<vector<int>> dp(capacity+1,vector<int> (n+1,-1));

    for(int row=0;row<=capacity;row++){
        dp[row][n]=0;
    }

    for(int i=0;i<=capacity;i++){
        for(int j=n-1;j>=0;j--){
            int include=0;
            int exclude=0;
            if(wt[j]<=i){
                include=profit[j]+dp[i-wt[j]][j+1];
            }
                
            exclude=0+dp[i][j+1];

            dp[i][j]=max(include,exclude);
        } 
    }
    return dp[capacity][0];
}

int solveUsingTabulationSO(int capacity,int wt[], int profit[],int n){
    vector<int> next(capacity+1,0);
    vector<int> curr(capacity+1,-1);


    
    for(int j=n-1;j>=0;j--){
        for(int i=0;i<=capacity;i++){
            int include=0;
            int exclude=0;
            if(wt[j]<=i){
                include=profit[j]+next[i-wt[j]];
            } 
                
            exclude=0+next[i];

            curr[i]=max(include,exclude);
        } 
        next=curr;
    }
    return curr[capacity];
}

// using only single array now 

int solveUsingTabulationSOFurther(int capacity,int wt[], int profit[],int n){
    vector<int> next(capacity+1,0);
    // vector<int> curr(capacity+1,-1);


    
    for(int j=n-1;j>=0;j--){
        for(int i=capacity;i>=0;i--){
            int include=0;
            int exclude=0;
            if(wt[j]<=i){
                include=profit[j]+next[i-wt[j]];
            } 
                
            exclude=0+next[i];

            next[i]=max(include,exclude);
        } 
        // next=curr; 
    }
    return next[capacity];
}

int main(){
    int capacity=50;
    int wt[]={10,20,30};
    int profit[]={60,100,120};
    int index=0;
    int n=3;

    int ans1=solveUsingRecursion(capacity,wt,profit,index,n);
    cout<<"Ans "<<ans1<<endl;

    vector<vector<int>> dp(capacity+1,vector<int> (n+1,-1));
    int ans2=solveUsingMemo(capacity,wt,profit,index,n,dp);
    cout<<"Ans: "<<ans2<<endl;

    // int capacity=4;
    // int wt[]={4,5,1};
    // int profit[]={1,2,3};
    // int index=0;
    // int n=3;

    // printDp(dp);

    int ans3=solveUsingTabulation(capacity,wt,profit,n);
    cout<<ans3<<endl;

    int ans4=solveUsingTabulationSO(capacity,wt,profit,n);
    cout<<ans4<<endl;

    int ans5=solveUsingTabulationSOFurther(capacity,wt,profit,n);
    cout<<ans5<<endl;
}