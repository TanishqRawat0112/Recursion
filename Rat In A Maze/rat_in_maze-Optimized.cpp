#include<iostream>
#include<string>
#include<vector>
using namespace std;

void solveMaze(vector<vector<int> >maze,int size,int row,int col,vector<vector<int> >&vis,string dir,vector<string>&ans){
    if(row==size && col==size){
        ans.push_back(dir);
        return;
    }
    //Downward Direction:
    if(row<size && vis[row+1][col]==0 && maze[row+1][col]==1){
        vis[row+1][col]=1;
        solveMaze(maze,size,row+1,col,vis,dir+"D",ans);
        vis[row+1][col]=0;
    }

    //Leftward Direction:
    if(col>0 && vis[row][col-1]==0 && maze[row][col-1]==1){
        vis[row][col-1]=1;
        solveMaze(maze,size,row,col-1,vis,dir+"L",ans);
        vis[row][col-1]=0;
    }

    //Rightward Direction:
    if(col<size && vis[row][col+1]==0 && maze[row][col+1]==1){
        vis[row][col+1]=1;
        solveMaze(maze,size,row,col+1,vis,dir+"R",ans);
        vis[row][col+1]=0;
    }

    //Upward Direction:
    if(row>0 && vis[row-1][col]==0 && maze[row-1][col]==1){
        vis[row-1][col]=1;
        solveMaze(maze,size,row-1,col,vis,dir+"U",ans);
        vis[row-1][col]=0;
    }
}
 
int main(){
    int n;
    cout<<"Enter the size of the Maze : ";
    cin>>n;

    vector<vector<int> >maze(n,vector<int>(n,0));
    cout<<"Enter the maze : "<<endl;
    int input;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>input;
            maze[i][j]=input;
        }
    }

    vector<vector<int> >vis(n,vector<int>(n,0));
    vector<string>ans;

    solveMaze(maze,n-1,0,0,vis,"",ans);

    for(auto it:ans){
        for(auto i:it){
            cout<<i<<"-->";
        }
        cout<<"Destination"<<endl;
    }

return 0;
}