#include<iostream>
using namespace std;

class Heap{
    public:
        int *arr; //random size
        int capacity;
        int size; //to keep track when array will be full

        Heap(int capacity){ // ctor to initialise
            this->arr=new int[capacity];
            this->capacity=capacity;
            // current number of elements in heap 
            this->size=0;
        }

        void insert(int val){
            if(size==capacity){
                cout<<"Heap Overflow"<<endl;
                return;
            }
            // on insertion size will increase 
            size++;
            int index=size;
            arr[index]=val;

            // take the value to its correct position
            while(index>1){
                int parentIndex=index/2;
                if(arr[index]>arr[parentIndex]){
                    swap(arr[index],arr[parentIndex]);
                    index=parentIndex; 
                }
                else{
                    break;
                }
            }
        }

        void printHeap(){
            cout<<"Printing the content of heap:"<<endl;
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }cout<<endl;       
        }        
};

void heapify(int *arr,int n,int index){
    int leftIndex=2*index;
    int rightIndex=2*index+1;
    int largetIndex=index;

    // max of these 3
    if(leftIndex<=n && arr[leftIndex]>arr[largetIndex]){
        largetIndex=leftIndex;
    }
    if(rightIndex<=n && arr[rightIndex]>arr[largetIndex]){
        largetIndex=rightIndex;
    }
    // these 2 conditions will make sure now that the largestIndex is pointing to the largest element
    if(index!=largetIndex){
        swap(arr[index],arr[largetIndex]);
        // rest recursion
        // now index is at largestIndex position 
        index=largetIndex;
        heapify(arr,n,index);
    }
}

void buildHeap(int arr[],int n){
    for(int index=n/2;index>0;index--){
        heapify(arr,n,index);
    }
}

void heapSort(int arr[],int n){
        while(n!=0){
            swap(arr[1],arr[n]);
            n--;
            heapify(arr,n,1);
        }
}

int main(){
    int arr[]={-1,5,10,15,20,25,12};
    int n=6;
    buildHeap(arr,n);
    for(int i=1;i<=6;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    heapSort(arr,n);
    for(int i=1;i<=6;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}