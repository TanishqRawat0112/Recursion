#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<vector<bool> >&graph,int nodes,int colored[],int current,int col){
    for(int k=0;k<nodes;k++){
        if(k!=current && graph[k][current]==1 && colored[k]==col){
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<bool> >&graph,int m,int nodes,int current,int colored[]){
    if(current==nodes){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(isValid(graph,nodes,colored,current,i)){
            colored[current]=i;
            if(solve(graph,m,nodes,current+1,colored)){
                return true;
            }
            colored[current]=0;
        }
    }
    return false;
}

bool graphColoring(vector<vector<bool> >&graph,int m,int nodes){
    int colored[nodes];
    for(int i=0;i<nodes;i++){
        colored[i]=0;
    }
    if(solve(graph,m,nodes,0,colored)){
        return true;
    }
    return false;
}
 
int main(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    cout<<"Enter the edges for each node : "<<endl;
    bool edge;
    vector<vector<bool> >graph;
    for(int i=0;i<n;i++){
        vector<bool>row;
        for(int j=0;j<n;j++){
            cin>>edge;
            row.push_back(edge);
        }
        graph.push_back(row);
    }

    int m;
    cout<<"Enter the number of colors available : ";
    cin>>m;

    

    if(graphColoring(graph,m,n)){
        cout<<"Yes these colors can be placed."<<endl;
    }
    else{
        cout<<"No, these colors can't be placed."<<endl;
    }
return 0;
}