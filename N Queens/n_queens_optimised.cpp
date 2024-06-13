#include<iostream>
#include<vector>
using namespace std;

void n_queens(vector<vector<int> >&chessboard,int size,int col,vector<vector<vector<int> > >&ans,vector<int>&leftRow,vector<int>&upperDiagonal,vector<int>&lowerDiagonal){
    if(col>size){
        ans.push_back(chessboard);
        return;
    }
    for(int i=0;i<=size;i++){
        if(leftRow[i]==0 && upperDiagonal[col+i]==0 && lowerDiagonal[size+col-i]==0){
            chessboard[i][col]=1;
            leftRow[i]=1;
            upperDiagonal[col+i]=1;
            lowerDiagonal[size+col-i]=1;
            n_queens(chessboard,size,col+1,ans,leftRow,upperDiagonal,lowerDiagonal);
            chessboard[i][col]=0;
            leftRow[i]=0;
            upperDiagonal[col+i]=0;
            lowerDiagonal[size+col-i]=0;
        }
    }
}
 
int main(){
    int n;
    cout<<"Enter the size of the chessboard : ";
    cin>>n;

    vector<vector<int> >chessboard(n,vector<int>(n,0));

    vector<vector<vector<int> > >ans;
    vector<int>leftRow(n,0);
    vector<int>upperDiagonal(2*n-1,0);
    vector<int>lowerDiagonal(2*n-1,0);
    n_queens(chessboard,n-1,0,ans,leftRow,upperDiagonal,lowerDiagonal);

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