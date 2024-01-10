#include<iostream>
using namespace std;

void printSum(int num1,int num2,int num3){
    int answer=num1+num2+num3;
    cout<<"The sum of the three numbers is "<<answer<<endl;
}

int returnSum(int num1,int num2,int num3){
    int answer=num1+num2+num3;
    return answer;
}

int main(){

    printSum(4,4,5);
    cout<<"Sum is "<<returnSum(4,4,5);


}