#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

template <typename T>

class Graph{
    public:
    unordered_map<T, list<pair<T,int> > > adjList;

    void addEdge(T u,T v,int wt,bool direction){
        if(direction == 1){
            // directed
            // u->v
            adjList[u].push_back({v,wt});
        }
        else{
            // undirected
            // u->v v->u
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
    }

    void printAdjList(){
        for(auto i:adjList){
            cout<<i.first<<": {";
            for(pair<T,int> p:i.second){
                cout<<"{"<<p.first<<", "<<p.second<<"} ";
            }
            cout<<"}"<<endl;
        }
    }

    void dfs(T src, unordered_map<T, bool> &vis){
        vis[src]=true;
        cout<< src<<" ";

        for(auto nbr:adjList[src]){
            T nbrData=nbr.first;
            if(!vis[nbrData]){
                dfs(nbrData,vis);
            }
        }
    }
};

int main(){
    Graph<char> g;
    g.addEdge('a','b',5,0);
    // g.addEdge('a','c',3,0); to make it disconnected
    g.addEdge('c','d',20,0);
    g.addEdge('c','e',50,0);
    g.addEdge('d','e',20,0);
    g.addEdge('e','f',50,0);

    unordered_map<char, bool> vis;

    for(char node='a'; node<= 'f';node++){
        if(!vis[node]){
            g.dfs(node,vis);
        }
    }
    
    

}