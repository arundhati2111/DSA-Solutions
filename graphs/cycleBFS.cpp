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

        bool checkCycleUndirectedBFS(int src){
            queue<int> q;
            unordered_map<int,bool> visited;
            unordered_map<int,int> parent;
            
            // to maintain initial state 
            q.push(src);
            visited[src]=true;
            parent[src]=-1;

            while(!q.empty()){
                int frontNode=q.front();
                q.pop();

                for(auto nbr:adjList[frontNode]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr]=true;
                        parent[nbr]=frontNode;
                    }

                    else if(visited[nbr]==true && nbr != parent[frontNode]){
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
    // g.addEdge(3,4,0);
    g.addEdge(2,5,0);

    int src=0;

    bool isCyclic = g.checkCycleUndirectedBFS(src);

    if(isCyclic){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle absent"<<endl;
    }
}