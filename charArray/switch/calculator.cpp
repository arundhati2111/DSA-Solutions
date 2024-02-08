#include<iostream>
using namespace std;

int main(){
    float num1,num2;
    cout<<"Enter two numbers: ";
    cin>>num1>>num2;
    int op;
    cout<<"Enter operator: ";
    cin>>op;
    float ans=0;
    switch(op){
        case 0:
        cout<<"Addition"<<endl;
            ans=num1+num2;
            break;
        case 1:
        cout<<"Subtraction"<<endl;
            ans=num1-num2;
            break;
        case 2:
        cout<<"Multiplication"<<endl;
            ans=num1*num2;
            break;
        case 3:
        cout<<"Division"<<endl;     ans=num1/num2;
            break;
        default:
            cout<<"Invalid operator!"<<endl;
            return 0;
    }
    cout<<"Ans is "<<ans<<endl;
}