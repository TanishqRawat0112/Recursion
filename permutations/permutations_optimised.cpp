#include<iostream>
#include<vector>
using namespace std;

void permut(vector<int> &arr,int size,int index,vector<vector<int> > &ans){
    if(index>size){
        ans.push_back(arr);
        return;
    }
    for(int i=index;i<=size;i++){
        swap(arr[i],arr[index]);
        permut(arr,size,index+1,ans);
        swap(arr[i],arr[index]);
    }
}
 
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    vector<int> arr;
    int inp;
    cout<<"Enter the array here : ";
    for(int i=0;i<n;i++){
        cin>>inp;
        arr.push_back(inp);
    }
    vector<int>list;
    vector<vector<int> >ans;
    permut(arr,n-1,0,ans);

    for(auto it:ans){
        cout<<"[";
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<"]"<<endl;
    }

return 0;
}