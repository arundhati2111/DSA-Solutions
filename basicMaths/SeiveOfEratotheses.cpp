#include<iostream>
#include<vector>
using namespace std;

vector<bool> Sieve(int n){
    vector<bool> sieve(n+1,true);
    sieve[0]=sieve[1]=false;
    for(int i=2;i*i<=n;i++){ //optimisation 2
        if(sieve[i]){
            int j=i*i; //Optmisation 1
            while(j<=n){
                sieve[i]=false;
                j+=i;
            }

        }
    }
    return sieve;
}

int main(){
    vector<bool> sieve= Sieve(25);
    for(int i=0;i<=25;i++){
        if(sieve[i]){
            cout<<i<<" ";
        }
    }
}