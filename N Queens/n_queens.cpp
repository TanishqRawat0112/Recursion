#include<iostream>
#include<vector>
using namespace std;

bool can_be_put(vector<vector<int> >&chessboard,int size,int col,int row){
    int tempRow=row;
    int tempCol=col;
    while(row>=0 && col>=0){
        if(chessboard[row][col]==1){
            return false;
        }
        row--;
        col--;
    }
    row=tempRow;
    col=tempCol;
    while(row<=size && col>=0){
        if(chessboard[row][col]==1){
            return false;
        }
        row++;
        col--;
    }
    row=tempRow;
    col=tempCol;
    while(col>=0){
        if(chessboard[row][col]==1){
            return false;
        }
        col--;
    }
    return true;
}

void n_queens(vector<vector<int> >&chessboard,int size,int col,vector<vector<vector<int> > >&ans){
    if(col>size){
        ans.push_back(chessboard);
        return;
    }
    for(int i=0;i<=size;i++){
        if(can_be_put(chessboard,size,col,i)){
            chessboard[i][col]=1;
            n_queens(chessboard,size,col+1,ans);
            chessboard[i][col]=0;
        }
    }
}
 
int main(){
    int n;
    cout<<"Enter the size of the chessboard : ";
    cin>>n;

    vector<vector<int> >chessboard(n,vector<int>(n,0));

    vector<vector<vector<int> > >ans;
    n_queens(chessboard,n-1,0,ans);

    for(auto it:ans){
        for(auto i:it){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<endl;

return 0;
}