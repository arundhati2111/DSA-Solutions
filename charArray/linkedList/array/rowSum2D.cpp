#include<iostream>
using namespace std;

void rowSum(int arr[][3],int row,int col){
    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<col;j++){
            sum+=arr[i][j];
        }
        cout<<"Sum for row "<<i<<" is "<<sum<<endl;
    }
}

void colSum(int arr[][3],int row,int col){
    for(int i=0;i<col;i++){
        int sum=0;
        for(int j=0;j<row;j++){
            sum+=arr[j][i];
        }
        cout<<"Sum for col "<<i<<" is "<<sum<<endl;
    }
}

void diagonalSum(int arr[][3],int row,int col){
    int sum=0;
    for(int i=0;i<row;i++){
        sum+=arr[i][i];
    }
    cout<<"Diagonal Sum of matrix is: "<<sum<<endl;
}

int main(){
    int arr[3][3]={
                  {10,20,5}, 
                  {2,4,6} ,  
                  {10,15,15}
                  };
    rowSum(arr,3,3);
    colSum(arr,3,3);
    diagonalSum(arr,3,3);
}