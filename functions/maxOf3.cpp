#include<iostream>
using namespace std;

void printMax(int num1,int num2,int num3){
    int ans1=max(num1,num2);
    int finalans=max(ans1,num3);
    cout<<"MAx is "<<finalans<<endl;
}

int returntMax(int num1,int num2,int num3){
    int ans1=max(num1,num2);
    int finalans=max(ans1,num3);
    return finalans;
}

int main(){

    printMax(4,10,300);

    cout<<returntMax(50,30,1);
}

