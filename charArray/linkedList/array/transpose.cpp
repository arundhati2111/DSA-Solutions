#include<iostream>
using namespace std;

void printArray(int arr[][3],int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void transpose(int arr[][3],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=i;j<col;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
}

int main(){
    int arr[3][3]={
                  {10,20,5}, 
                  {2,4,6} ,  
                  {10,15,15}
                  };
    transpose(arr,3,3);
    printArray(arr,3,3);

}