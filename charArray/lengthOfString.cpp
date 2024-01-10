#include<iostream>
#include<string.h>
using namespace std;

int findLength(char ch[],int n){
    // int length=0;
    // for(int i=0;i<n;i++){
    //     if(ch[i]=='\0'){
    //         break;
    //     }
    //     else{
    //         length++;
    //     }
    // }


    // int index=0;
    // while(ch[index]!='\0'){
    //     length++;
    //     index++;
    // }
    // return length;

    int index=0;
    while(ch[index]!='\0'){
        index++;
    }
    return index;
}

int main(){
    char ch[100];
    cin>>ch;
    int len=findLength(ch,100);
    int len2=strlen(ch);
    cout<<"The length of the string is "<<len<<endl;
    cout<<"The length of the string using built in func is "<<len2<<endl;
}