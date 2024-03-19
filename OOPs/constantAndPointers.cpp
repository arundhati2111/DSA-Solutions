#include<iostream>
using namespace std;

int main(){
    // const int *a=new int(2);
    // // int const *a=new int(2);
    // cout<<*a<<endl;
    // // *a=20 not possible
    // int b=20;
    // a=&b; //pointer itself can be reassigned 
    // cout<<*a<<endl;

    int *const b = new int(3);
    cout<<*b<<endl; 
    *b = 15; 
    cout<<*b<<endl;
    int c=50;
    // b=&c; is not possible 

    const int *const a=new int(2);
    cout<<*a<<endl;
    // *a=20;
    // int d=30;
    // a=&d; both not possible 
    


}