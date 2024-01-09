#include<iostream>

using namespace std;

class KQueues{
    public:
    int k,n,freespot;
    int *arr,*front,*rear,*next;

    KQueues(int _n,int _k):n(_n),k(_k),freespot(0){
        arr=new int[n];
        next=new int[n];
        front=new int[k];
        rear=new int[k];
        // initialising front and rear with -1
        for(int i=0;i<k;i++){
            front[i]=rear[i]=-1;
        }
        // initialising next
        for(int i=0;i<n;i++){
            next[i]=i+1;
        }
        next[n-1]=-1; //last index 

    }
        // push x into qith queue
        bool push(int x,int qi){
            if(freespot==-1){
                return false;
            }
            // find first free index 
            int index=freespot;

            // update freespot
            freespot=next[index];

            // first element
            if(front[qi]==-1){
                front[qi]=index;
            }
            else{
                // link new element to that Q's rearest element
                next[rear[qi]]=index; 
            }

            // update next
            next[index]=-1;

            // update rear
            rear[qi]=index;
            arr[index]=x;

            return true;

        }

        // pop element from qith queue
        int pop(int qi){
            // underflow
            if(front[qi]==-1){
                return -1;
            }
            // find index to pop
            int index=front[qi];

            // update front
            front[qi]=next[index];

            // update freespot
            next[index]=freespot;

            freespot=index;

            return arr[index];
        }

        ~KQueues(){
            delete []arr;
            delete []front;
            delete []rear;
            delete []next;
        }
};

int main(){
    KQueues kq(8,3);
    cout<<kq.push(1,0)<<endl;
    cout<<kq.push(2,0)<<endl;
    cout<<kq.push(5,1)<<endl;
    cout<<kq.push(3,0)<<endl;
    cout<<kq.pop(1)<<endl;
    cout<<kq.pop(1)<<endl;
    cout<<kq.pop(0)<<endl;
    cout<<kq.pop(0)<<endl;
    cout<<kq.pop(0)<<endl;
    cout<<kq.pop(0)<<endl;
    cout<<kq.pop(0)<<endl;
    cout<<kq.pop(1)<<endl;
}
