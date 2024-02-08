#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void printvv(vector<vector<int>> &v){
    for(int i=0;i<v.size();i++){
        vector<int> &temp=v[i];
        int a=temp[0];
        int b=temp[1];
        cout<<a<<" "<<b<<endl;
    }
    cout<<endl;
}

bool mycomp(int &a,int &b){
    // return a<b; //ascending
    return a>b; //descending
}

bool mycomp1stIndex(vector<int> &a,vector<int> &b){
    return a[1]<b[1];
}

int main(){
    vector<int> v={22,33,11,90,8};
    sort(v.begin(),v.end());
    print(v);
    sort(v.begin(),v.end(),mycomp);
    print(v);

    // VECTOR OF VECTOR 
    vector<vector<int>> vv;
    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cout<<"Enter the values of a and b: ";
        cin>>a>>b;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        vv.push_back(temp);
    }
    cout<<"Vector of vector is: "<<endl;
    printvv(vv);
    sort(vv.begin(),vv.end());
    printvv(vv);
    sort(vv.begin(),vv.end(),mycomp1stIndex);
    printvv(vv);
}
