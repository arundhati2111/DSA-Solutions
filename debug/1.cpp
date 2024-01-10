
#include<iostream>
using namespace std;

int function(int n)

{

if (n%4 == 0) return 0;

if (n%4 == 1) return 1;

if (n%4 == 2) return n+1;

else 
return 0;

}

int main() {
	// char c;
    // cin>>c;
    // if('a'<=c && c<= 'z'){
    //     cout<<0;
    // }
	// else if('A'<=c && c<= 'Z'){
    //     cout<<1;
    // }
    // else{
    //     cout<<-1;
    // }

    // if(~0==1){
    //     cout<<"Yes";
    // }
    // else{
    //     cout<<"NO";
    // }

    // int x=-7;
    // x=x>>1;
    // cout<<x;

    // int x=10;
    // char y='a';
    // x=x+y;
    // cout<<x;

    int fun=function(10);
    cout<<fun;
}


//  replaced with &&