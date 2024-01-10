#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int maze[][4],int rows,int cols,int srcx,int srcy,vector<vector<bool>> &visited,int newx,int newy){
    if(
        (newx>=0 && newx<=rows) && 
        (newy>=0 && newy<=cols) &&
        maze[newx][newy]==1 &&
        visited[newx][newy]==false
    ){
        return true;
    }
    else{
        return false;
    }
}

void ratInMaze(int maze[][4],int rows,int cols,int srcx,int srcy,string &output,vector<vector<bool>> &visited){
    // base case destination reached
    if(srcx==rows-1 && srcy==cols-1){
        cout<<output<<endl;
        return;
    }
    // up
    int newx=srcx-1;
    int newy=srcy;
    if(isSafe(maze,rows,cols,srcx,srcy,visited,newx,newy)){
        visited[newx][newy]=true;
        output.push_back('U');
        ratInMaze(maze,rows,cols,newx,newy,output,visited);
        output.pop_back();
        visited[newx][newy]=false;
    }

    // right
    newx=srcx;
    newy=srcy+1;
    if(isSafe(maze,rows,cols,srcx,srcy,visited,newx,newy)){
        visited[newx][newy]=true;
        output.push_back('R');
        ratInMaze(maze,rows,cols,newx,newy,output,visited);
        output.pop_back();
        visited[newx][newy]=false;
    }

    // left
    newx=srcx;
    newy=srcy-1;
    if(isSafe(maze,rows,cols,srcx,srcy,visited,newx,newy)){
        visited[newx][newy]=true;
        output.push_back('L');
        ratInMaze(maze,rows,cols,newx,newy,output,visited);
        output.pop_back();
        visited[newx][newy]=false;
    }

    // down
    newx=srcx+1;
    newy=srcy;
    if(isSafe(maze,rows,cols,srcx,srcy,visited,newx,newy)){
        visited[newx][newy]=true;
        output.push_back('D');
        ratInMaze(maze,rows,cols,newx,newy,output,visited);
        output.pop_back();
        visited[newx][newy]=false;
    }

}

int main(){
    int maze[4][4]={
        {1,0,0,0},
        {1,1,0,0},
        {1,1,1,0},
        {1,1,1,1}
    };
    int rows=4;
    int cols=4;

    int srcx=0;
    int srcy=0;

    string output="";

    vector<vector<bool>> visited(rows,vector<bool>(cols,false));

    if(maze[0][0]==0){
        cout<<"No path exist"<<endl;
    }

    else{
        visited[srcx][srcy]=true;
        ratInMaze(maze,rows,cols,srcx,srcy,output,visited);
    }

    
}