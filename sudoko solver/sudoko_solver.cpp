#include<iostream>
using namespace std;

bool isValid(int sudoko_board[9][9],int row,int col,int put){
    for(int i=0;i<9;i++){
        if(sudoko_board[row][i]==put){
            return false;
        }
        if(sudoko_board[i][col]==put){
            return false;
        }
        if(sudoko_board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==put){
            return false;
        }
    }
    return true;
}

bool solve(int sudoko_board[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sudoko_board[i][j]==0){
                for(int c=1;c<=9;c++){
                    if(isValid(sudoko_board,i,j,c)){
                        sudoko_board[i][j]=c;
                        if(solve(sudoko_board)==true){
                            return true;
                        }
                        else{
                            sudoko_board[i][j]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}


 
int main(){
    int sudoko_board[9][9];
    cout<<"Enter the sudoko Board(Enter 0 where the board is empty) : ";
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>sudoko_board[i][j];
        }
    }
    bool temp=solve(sudoko_board);

    cout<<endl;
    cout<<"Solved Sudoko Board will be : "<<endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<sudoko_board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
return 0;
}