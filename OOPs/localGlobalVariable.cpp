#include<iostream>
using namespace std;

int x=2; //global variable 

void fun(){
    int x=60;
    cout<<x<<endl;
    cout<< ::x <<endl;
}


int main(){
    x=20; //global x accessed 
    int x=4;
    cout<<x<<endl;
    cout<<::x<<endl;

    {
        int x=50;{
            int x=44;
            cout<<x<<endl;
        }
        cout<<x<<endl;
        cout<<::x<<endl;
    }
    fun();
    
    return 0;
}