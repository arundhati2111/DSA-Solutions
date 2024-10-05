#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    // creation
    unordered_map<string,int> mapping;

    // insertion
    pair<string,int> p=make_pair("Arundhati",21);
    pair<string,int> q("Pratham",22); 
    pair<string,int> r;
    r.first="Akankshi";
    r.second=21;

    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);
    mapping["Shraddha"]=20;

    cout<<"Size of map "<<mapping.size()<<endl;

    // access
    cout<<mapping.at("Arundhati")<<endl;  
    cout<<mapping["Pratham"]<<endl;

    // search
    cout<<mapping.count("Shraddha")<<endl;
    cout<<mapping.count("Siya")<<endl;

    if(mapping.find("Pratham") != mapping.end()){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }

    cout<<"Size of map "<<mapping.size()<<endl;
    cout<<mapping["Tushar"]<<endl;
    cout<<"Size of map "<<mapping.size()<<endl;
    cout<<mapping["Tushar"]<<endl;
    cout<<"Size of map "<<mapping.size()<<endl;

}