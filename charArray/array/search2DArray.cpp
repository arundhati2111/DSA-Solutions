#include<iostream>
using namespace std;

bool findTarget(int arr[][4],int row,int col,int target){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==target){
                return true;
            }
        }
    }
    // all elements checked and element not found
    return false;
}

int main(){
    int arr[3][4]={
                  {1,2,3,4},
                  {5,6,7,8} ,  
                  {9,10,11,12}
                  };
    int row=3;
    int col=3;
    int target=11;
    bool ans=findTarget(arr,row,col,target);
    if(ans){
        cout<<"Target found"<<endl;
    }
    else{
        cout<<"Target not found"<<endl;
    }

}