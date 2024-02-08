#include<iostream>
#include<limits.h>
using namespace std;


int maxLength(int n,int x, int y, int z){
    if(n==0) return 0;
    if(n<0) return INT_MIN;

    int op1=1+maxLength(n-x,x,y,z);
    int op2=1+maxLength(n-y,x,y,z);
    int op3=1+maxLength(n-z,x,y,z);
    int finalAns=max(op1,op2,op3);
    return finalAns;
}