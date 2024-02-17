#include<iostream>
#include<limits.h>
using namespace std;

int maxAns(int arr[][4],int row,int col){
    int maxAns=INT_MIN;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]>maxAns){
                maxAns=arr[i][j];
            }
        }
    }
    return maxAns;
}

int minAns(int arr[][4],int row,int col){
    int minAns=INT_MAX;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]<minAns){
                minAns=arr[i][j];
            }
        }
    }
    return minAns;
}

int main(){
    int arr[3][4]={
                  {1,2,3,4},
                  {5,6,70,8} ,  
                  {9,10,11,12}
                  };
    int row=3;
    int col=4;
    int maxans=maxAns(arr,row,col);
    cout<<"Max is "<<maxans<<endl;

    int minans=minAns(arr,row,col);
    cout<<"Min is "<<minans;

}