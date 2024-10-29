#include<iostream>
#include<unordered_map>
#include<map>
#include<stack>
#include<list>
#include<queue>
#include<vector>
#include<algorithm>
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


        void shortestPathBFS(int src,int dest){
            queue<int> q;
            map<int,bool> visited;
            map<int,int> parent;

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
                        parent[nbr]=frontNode;
                        visited[nbr]=true;
                    }
                }
            }

            // parent array is ready
            vector<int> ans;
            while(dest != -1){
                ans.push_back(dest);
                dest=parent[dest];
            }
            // this way the answer is reverse
            reverse(ans.begin(),ans.end());

            // printing the shortest path
            for(auto i:ans){
                cout<<i<<" ";
            }
        }
};

int main(){

    Graph g;
    g.addEdge(0,5,0);
    g.addEdge(5,4,0);
    g.addEdge(4,3,0);
    g.addEdge(0,6,0);
    g.addEdge(6,3,0);
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);

    // int n=8;
    int src=0;
    int dest=3;

    g.shortestPathBFS(src,dest);

}