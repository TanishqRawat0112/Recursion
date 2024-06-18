#include<iostream>
#include<string>
#include<vector>
using namespace std;

void solveMaze(vector<vector<int> >maze,int size,int row,int col,vector<vector<int> >&vis,string dir,vector<string>&ans,int dirRow[],int dirCol[]){
    if(row==size && col==size){
        ans.push_back(dir);
        return;
    }
    string direction="DLRU";
    for(int i=0;i<4;i++){
        int nextRow=row+dirRow[i];
        int nextCol=col + dirCol[i];
        if(nextRow>=0 && nextRow<=size && nextCol>=0 && nextCol<=size && vis[nextRow][nextCol]==0 && maze[nextRow][nextCol]==1){
            vis[nextRow][nextCol]=1;
            solveMaze(maze,size,nextRow,nextCol,vis,dir+direction[i],ans,dirRow,dirCol);
            vis[nextRow][nextCol]=0;
        }
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
    int dirRow[]={+1,0,0,-1};
    int dirCol[]={0,-1,+1,0};

    solveMaze(maze,n-1,0,0,vis,"",ans,dirRow,dirCol);

    for(auto it:ans){
        for(auto i:it){
            cout<<i<<"-->";
        }
        cout<<"Destination"<<endl;
    }

return 0;
}