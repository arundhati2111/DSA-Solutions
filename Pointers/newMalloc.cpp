#include<iostream>
using namespace std;

void print(int** v,int rows,int col){
    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }
}

int main(){
    // 1. int allocation
    // using new
    int* intPtr=new int(10);
    // using malloc
    int* mptr=(int*) malloc(4);
    *mptr=5;
    cout<<"intPtr: "<<*intPtr<<" mptr: "<<*mptr<<endl;

    // releasing memory manually from heap
    delete intPtr;
    free(mptr);

    // 2. array allocation 
    // using new
    int* arrNew=new int[5];
    // using malloc
    int* arrMalloc=(int*)malloc(5*sizeof(int));

    // entering values
    for(int i=0;i<5;i++){
        int d;
        cout<<"Enter the value: "<<endl;
        cin>>d;
        arrNew[i]=arrMalloc[i]=d;
    }

    // printing values
    for(int i=0;i<5;i++){
        cout<<arrNew[i]<<" "<<arrMalloc[i]<<endl;
    }

    delete[] arrNew;
    free(arrMalloc);

    // 3. 2D array allocation
    // new
    int rows=5,col=5;
    int** ptr2D=new int*[rows];
    for(int i=0;i<rows;i++){
        ptr2D[i]=new int[col];
    }

    int** ptr2Dmalloc=(int**)malloc(sizeof(int*)*rows);
    for(int i=0;i<rows;i++){
        ptr2Dmalloc[i]=(int*)malloc(sizeof(int)*col);
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            ptr2D[i][j]=7;
            ptr2Dmalloc[i][j]=8;
        }
    }

    print(ptr2D,rows,col);
    print(ptr2Dmalloc,rows,col);

    for(int i=0;i<rows;i++){
        delete[] ptr2D[i];
    }
    delete[] ptr2D;

    for(int i=0;i<rows;i++){
        free(ptr2Dmalloc[i]);
    }
    free(ptr2Dmalloc);
    
    return 0;

}