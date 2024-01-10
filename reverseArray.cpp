#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

void reverseArray(char ch[],int size){
    int i=0;
    int j=size-1;
    while(i<=j){
        swap(ch[i],ch[j]);
        i++;
        j--;
    }
}

int main(){
    char ch[100];
    cin.getline(ch,100);
    int len=strlen(ch);
    cout<<"Before reverse: "<<ch<<endl;
    reverseArray(ch,len);
    cout<<"Reversed: "<<ch<<endl;
}