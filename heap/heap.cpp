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

        int deleteRoot(){
            int answer=arr[1];
            arr[1]=arr[size];
            size--;

            int index=1;
            while(index<size){
                int leftIndex=2*index;
                int rightIndex=2*index+1;

                int largestIndex=index; //suppose
                if(leftIndex<=size && arr[largestIndex]<arr[leftIndex]){
                    largestIndex=leftIndex;
                }
                if(rightIndex<=size && arr[largestIndex]<arr[rightIndex]){
                    largestIndex=rightIndex;
                }

                // no change
                if(index==largestIndex){
                    break;
                }
                else{
                    swap(arr[index],arr[largestIndex]);
                    index=largestIndex;
                }
            }
            return answer;
        }
};

int main(){
    Heap h(20); 
    // insert
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);

    h.printHeap();

    int ans=h.deleteRoot();
    cout<<"Deleted node is: "<<ans<<endl;

    cout<<"Heap after deletion:"<<endl;
    h.printHeap();

    return 0;    
}