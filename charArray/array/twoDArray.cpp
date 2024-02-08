#include<iostream>
using namespace std;

void printArray(int arr[][4],int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printArrayCol(int arr[][4],int row, int col){
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[3][4]={
                  {1,2,3,4},
                  {5,6,7,8} ,  
                  {9,10,11,12}
                  };
    int arr2[3][3];
    int row=3;
    int col=3;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"Enter the input for row "<<i<<" and column "<<j<<endl;
            cin>>arr2[i][j];
        }
    }

    cout<<"Printing row wise"<<endl;
    printArray(arr,row,col);
    cout<<"Printing col  wise"<<endl;
    printArrayCol(arr,row,col);
}