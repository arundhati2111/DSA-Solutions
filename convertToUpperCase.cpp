#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

void convertToUpperCase(char ch[]){
    int index=0;
    while(ch[index]!='\0'){
        char currCharacter=ch[index];
        if(currCharacter>='a' && currCharacter<='z'){
            // lower case 
            // converting to upper case 
            ch[index]=currCharacter-'a'+'A';
        }
        index++;
    }
}

int main(){
    char ch[100];
    cout<<"Enter the Character Array: ";
    cin.getline(ch,100);
    cout<<"Original char array: "<<ch<<endl;
    convertToUpperCase(ch);
    cout<<"Upper case char array: "<<ch<<endl;

}