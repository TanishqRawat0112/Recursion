#include<iostream>
#include<vector>
using namespace std;

void print_subsequence(vector<int>arr,int index,int size,vector<vector<int> >&ans,vector<int>&list){
    if(index==size){
        // cout<<"added in ans"<<endl;
        ans.push_back(list);
        return;
    }
    list.push_back(arr[index]);
    print_subsequence(arr,index+1,size,ans,list);
    list.pop_back();
    print_subsequence(arr,index+1,size,ans,list);
}
 
int main(){
    int n;
    cout<<"Enter the length of the array : ";
    cin>>n;
    vector<int>arr;
    int inp;
    cout<<"Enter the array : ";
    for(int i=0;i<n;i++){
        cin>>inp;
        arr.push_back(inp);
    }
    vector<vector<int> > ans;
    vector<int> list;
    print_subsequence(arr,0,n,ans,list);

    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
return 0;
}