#include<iostream>
#include<string>
#include<vector>
using namespace std;

string direction(int i){
    switch(i){
        case 0:
            return "D";
            break;
        case 1:
            return "L";
            break;
        case 2:
            return "R";
            break;
        default:
            return "U";
    }
}

bool canMove(vector<vector<int> >&maze,int &size,int &row,int &col,vector<vector<int> >&vis,int dir){
    if(dir==0){
       if(row<size && maze[row+1][col]==1 && vis[row+1][col]==0){
            row++;
            return true;
        } 
        return false;
    }
    else if(dir==1){
        if(col>0 && maze[row][col-1]==1 && vis[row][col-1]==0){
            col--;
            return true;
        }
        return false;
    }
    else if(dir==2){
        if(col<size && maze[row][col+1]==1 && vis[row][col+1]==0){
            col++;
            return true;
        }
        return false;
    }
    else if(dir==3){
        if(row>0 && maze[row-1][col]==1 && vis[row-1][col]==0){
            row--;
            return true;
        }
        return false;
    }
    return false;
}

void solveMaze(vector<vector<int> >&maze,int &size,int &row,int &col,vector<vector<int> >&vis,vector<string>&list,vector<vector<string> >&ans){
    if(row==size && col==size){
        ans.push_back(list);
        return;
    }
    for(int i=0;i<4;i++){
        if(canMove(maze,size,row,col,vis,i)){
            vis[row][col]=1;
            string dir="";
            dir+=direction(i);
            list.push_back(dir);
            solveMaze(maze,size,row,col,vis,list,ans);
            list.pop_back();
            vis[row][col]=0;
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
    
    vector<string>list;
    vector<vector<string> >ans;
    int size=n-1;
    int row=0;
    int col=0;

    solveMaze(maze,size,row,col,vis,list,ans);

    for(auto it:ans){
        for(auto i:it){
            cout<<i<<"-->";
        }
        cout<<"Destination"<<endl;
    }

return 0;

}