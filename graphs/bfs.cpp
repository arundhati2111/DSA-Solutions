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

    void bfsTraversal(T src, unordered_map<T, bool> &vis){
        // visited
        
        // queue
        queue<T> q;

        // initial state maintained
        q.push(src);
        vis[src]=true;

        while(!q.empty()){
            T frontNode=q.front();
            cout<<frontNode<<" ";
            q.pop();

            // go to neighbour
            for(auto nbr: adjList[frontNode]){
                T nbrData=nbr.first;

                if(!vis[nbrData]){
                    // not visited
                    q.push(nbrData);
                    vis[nbrData]=true;
                }
            }
        }

    }
};



int main(){
    // // Graph<int> g;
    // // // g.addEdge(0,1,5,1);
    // // // g.addEdge(1,2,10,1);
    // // // g.addEdge(1,3,20,1);
    // // // g.addEdge(2,3,50,1);
    // // g.addEdge(0,1,5,0);
    // // g.addEdge(1,2,10,0);
    // // g.addEdge(1,3,20,0);
    // // g.addEdge(2,3,50,0);
    // // g.printAdjList();

    // Graph<char> g2;
    // g2.addEdge('A','B',5,0);
    // g2.addEdge('A','C',10,0);
    // g2.addEdge('B','C',20,0);
    // g2.addEdge('C','D',50,0);
    // g2.addEdge('C','E',50,0);
    // g2.addEdge('E','F',50,0);
    // g2.printAdjList();

    // g2.bfsTraversal('A');

    // DISCONNECTED GRAPH
    Graph<char> g3;
    g3.addEdge('A','B',5,0);
    g3.addEdge('B','C',10,0);

    g3.addEdge('D','E',20,0);

    g3.addEdge('F','F',50,0);
    g3.printAdjList();

    unordered_map<char, bool> vis;

    for(char node='A';node<='F';node++){
        if(!vis[node]){
            g3.bfsTraversal(node,vis);
        }
    }

    // g3.bfsTraversal('A');

}