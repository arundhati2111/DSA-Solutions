#include<iostream>
using namespace std;

#define PI 3.14159
#define MAXX(a,b) (a>b?a:b);

float areaOfCircle(float r){
    return PI*r*r;
}

float perimeterOfCircle(float r){
    return 2*PI*r;
}

void fun1(){
    int a=10;
    int b=20;
    int c=MAXX(a,b);
}

void fun2(){
    int x=67;
    int y=29;
    int z=MAXX(x,y);
}

int main(){
    cout<<areaOfCircle(74.2)<<endl;
    cout<<perimeterOfCircle(65.4)<<endl;
}