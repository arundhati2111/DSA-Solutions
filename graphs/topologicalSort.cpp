#include<iostream>
#include<unordered_map>
#include<map>
#include<stack>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class Graph{
    public:
        unordered_map<int,list<int>> adjList;

        void addEdge(int u,int v,bool direction){
            // direction =0 means undirected 
            // direction =1 means directed 
            if(direction==1){
                adjList[u].push_back(v);
            }
            else{
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }

        void print(){
            for(auto i:adjList){
                cout<<i.first<<": {";
                for(auto j:i.second){
                    cout<<j<<", ";
                }
                cout<<"}"<<endl;
            }
        }

        void topoSortDFS(int src,map<int,bool> &visited,stack<int> &st){
            visited[src]=true;

            for(auto nbr:adjList[src]){
                if(!visited[nbr]){
                    topoSortDFS(nbr,visited,st);
                }
            }

            st.push(src);

        }

        void topoSortBFS(int n,vector<int> &topoOrder){
            queue<int> q;
            unordered_map<int,int> indegree;
            // initialise indegree
            for(auto i:adjList){
                for(auto nbr:i.second){
                    indegree[nbr]++;
                }
            }
            // push all nodes with indegree 0 in queue
            for(int node=0;node<n;node++){
                if(indegree[node]==0){
                    q.push(node);
                }
            }

            // bfs 
            while(!q.empty()){
                int frontNode=q.front();
                q.pop();
                // cout<<frontNode<<", ";
                topoOrder.push_back(frontNode);

                for(auto nbr:adjList[frontNode]){
                    indegree[nbr]--;

                    // check for zero
                    if(indegree[nbr]==0){
                        q.push(nbr);
                    }
                }

            }
        }
};

int main(){

    // Graph g;
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(2,3,1);
    // g.addEdge(3,4,1);
    // g.addEdge(3,5,1);
    // g.addEdge(4,6,1);
    // g.addEdge(5,6,1);
    // g.addEdge(6,7,1);

    // g.print();

    // int n=8;

    // map<int,bool> visited;
    // stack<int> st;

    // // for disconnected graphs
    // for(int node=0;node<n;node++){
    //     if(!visited[node]){
    //         g.topoSortDFS(node,visited,st);
    //     }
    // }
    // cout<<"Prinitng the topological order"<<endl;
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(2,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,5,1);
    g.addEdge(5,6,1);
    g.addEdge(5,7,1);

    int n=8;
    vector<int> topoOrder;
    g.topoSortBFS(n,topoOrder);

    cout<<"Printing the topoOrder"<<endl;
    for(auto i:topoOrder){
        cout<<i<<" ";
    }

    if(topoOrder.size()==n){
        cout<<"No cycle"<<endl;
    }

    else{
        cout<<"Cycle found"<<endl;
    }


}