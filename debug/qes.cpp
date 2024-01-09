#include<iostream>
using namespace std;

void permute(string& a, int l, int r){

if (l== r)
cout << a << endl; 
else { 
    for (int i = l; i <= r; i++) { 
        swap(a[l], a[i]); permute(a, l+ 1, r); 
        swap(a[l], a[i]);

}

}

}

int main()

{

string a ="abc";

permute(a,0,2);

}

// void print(int n, int j){

// if (j >= n)

// return; 
// if (n-j> 0 && n-j>=j) cout <<j<<" "<<n-j<<endl;

// print(n, j+1);
// }
// int main(){

// int n = 8;

// print(n,1);}


// // int f (int n){

// // int x = 1, k;

// // if (n == 1)

// // return x; for (k = 1; k < n; ++k) x = x + f(k) * f(n - k);

// // return x;
// // }

// // int main()

// // { cout << f(6);

// // }

// // // void f(int n, int a, int b){

// // // if (n<=0) return;

// // // f(n-1, a, b + n);

// // //  cout <<n<<"" <<"" << a <<""<<b<<endl; 

// // // f(n-1, b, a+n);}

// // // int main(){

// // // f(3, 4,5);

// // // }

// // // int fun(int n, int *f_p){

// // // int t, f;

// // // if (n <= 1){

// // // *f_p = 1; return 1;

// // // }

// // // t = fun(n-1,f_p);

// // // f=t+*f_p;

// // // *f_p=t; 
// // // return f;}

// // // int main(){

// // // int x = 15; cout << fun(7, &x) << endl;

// // // }

// // // int f(int a[],int i, int n){

// // // if(n <= 0) return 0;

// // // else if(a[i] % 2 == 0) return a[i] + f(a, i+1, n-1); else return a[i] - f(a, i+1, n-1); }

// // // int main()

// // // {

// // // int a[] = {12, 7, 13, 4, 11, 6}; 
// // // cout << f(a, 2, 4) << endl;}

// // // int f(int a[],int i, int n){

// // // if(n <= 0) return 0;

// // // else if(a[i] % 2 == 0) return a[i] + f(a, i+1, n-1); else return ali] - f(a, i+1, n-1); }

// // // int main()

// // // {

// // // int a[] = {12, 7, 13, 4, 11, 6); cout << f(a, 2, 4) << endl; return 0; }int f(int a[],int i, int n){

// // // if(n <= 0) return 0;

// // // else if(a[i] % 2 == 0) return a[i] + f(a, i+1, n-1); else return ali] - f(a, i+1, n-1); }

// // // int main()

// // // {

// // int a[] = {12, 7, 13, 4, 11, 6); cout << f(a, 2, 4) << endl; return 0; }

// // int f(int n){

// // if(n <= 1)

// // return 1;

// // if(n%2==0)

// // return f(n/2);

// // return f(n/2)+ f(n/2+1);

// // }

// // int main(){

// // cout << f(15) << endl;

// // // return 0;

// // }

// // void print(int n){

// // if (n> 4000)

// // return; cout << n << " ";
// // print(2*n);
// // cout << n << " ";



// // }


// // int main()

// // {

// // print(500);


// // }

// // void fun(int n){

// // if (n == 0)

// // return;

// // cout << n % 2; fun(n/2);

// // }

// // int main(){

// // fun(11);

// // }

// // int fun(int x, int y)

// // { if (x == 0) return y; 
// // return fun(x - 1, x + y);}

// // int main(){
// // cout<<"H";
// // cout << fun(5, 2) << endl;
// // cout<<"d";


// // }
// // int fun(int n)

// // { 

// // if (n == 4) return n;
// // else return 2*fun(n+1);}

// // int main()

// // {

// // cout << fun(3) << endl;


// // }
// // int f(int n, int r){

// // if(n>0){

// // return n % r + f(n/r, r);

// // return 0;

// // }}

// // int main(){

// // cout << f(511, 2) << endl;

// // }

// // int g(int x);

// // int f(int x){

// // if(x < 1) return 1; else return (f(x-1) + g(x)); }

// // int g(int x){

// // if(x < 2) return 2;

// // else return (f(x-1)+ g(x/2));

// // }

// // int main(){

// // cout << f(4) << endl;

// // return 0;



// // }

// // int fun(int x, int y){ if(y <= 0) return x; return fun(y, x%y); }

// // int main(){
// //     int a=fun(1,2);
// //     int b=fun(6,3);
// //     int c=fun(9,27);
// //     cout<<a<<endl;
// //     cout<<b<<endl;
// // }

// // void fun(int n); 
// // void fun2(int n);

// // void fun1(int n){

// // cout << n;

// // if(n == 0) return; fun2(n-2); 

// // cout<<n;
// // }

// // void fun2(int n){

// // if(n == 0) return; fun1(++n);

// // cout << n;

// // cout << n;}

// // int main(){

// //     fun1(4);
// //     return 0;
// // } 
// // int doSomething(int a, int b){

// // if (b==1)

// // return a;

// // else

// // return a + doSomething(a,b-1);

// // }

// // int main() {

// // cout << doSomething(2,3) << endl; return 0;

// // }


// // int rec(int num){

// // return (num) ? num + rec(num/10):0;

// // }

// // int main(){

// // cout << rec(4657)<<endl;

// // }



