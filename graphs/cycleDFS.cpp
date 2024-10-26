#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<int> > adjList;
        void addEdge(int u,int v,bool direction){
            if(direction==1){
                // directed edge
                // u->v
                adjList[u].push_back(v);

            }
            
            else{
                // undirected edge
                // u->v v->u
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }

        void printAdjList(){
            for(auto i:adjList){
                cout<<i.first<<"-> {";
                for(auto neighbour:i.second){
                    cout<<neighbour<<", ";
                }
                cout<<"}"<<endl; 
            }
        }

        bool checkCycleUndirectedDFS(int src, unordered_map<int,bool> &visited){
            // visited[src]=true;
            // for(auto nbr: adjList[src]){
            //     if(nbr==parent){
            //         continue;
            //     }
            //     if(!visited[nbr]){
            //         bool ans= checkCycleUndirectedDFS(nbr,visited,src);
            //         if(ans==true){
            //             return true;
            //         }
            //     }
            //     else if(visited[nbr]==1){
            //         return true;
            //     }
            // }
            // return false;

            queue<int> q;
            // unordered_map<int,bool> visited;
            unordered_map<int,int> parent;
            
            // to maintain initial state 
            q.push(src);
            visited[src]=true;
            parent[src]=-1;

            while(!q.empty()){
                int frontNode=q.front();
                q.pop();

                for(auto nbr:adjList[frontNode]){
                    if(nbr==parent[frontNode]){
                        continue;
                    }
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr]=true;
                        parent[nbr]=frontNode;
                    }

                    else if(visited[nbr]==true ){
                        // cycle present
                        return true;
                    }
                }
            }
            // cycle not present 
            return false;
        }
};

int main(){
    Graph g;

    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(2,4,0);
    g.addEdge(3,4,0);
    g.addEdge(2,5,0);

    int src=0;

    unordered_map<int,bool> visited;
    int V=5;

    for(int i=0;i<V;i++){
        if(!visited[i]){
            int parent =-1;
            bool isCyclic = g.checkCycleUndirectedDFS(i,visited);
            if(isCyclic){
                cout<<"Cycle is present"<<endl;
            }
            else{
                cout<<"Cycle absent"<<endl;
            }
        }
    }

    

    
    
}