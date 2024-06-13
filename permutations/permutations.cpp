#include<iostream>
#include<vector>
using namespace std;

void permut(int arr[],int size,int hashArr[],vector<int>&list,vector<vector<int> > &ans){
    if(list.size()==size+1){
        ans.push_back(list);
        return;
    }
    for(int i=0;i<=size;i++){
        if(hashArr[i]==0){
            hashArr[i]=1;
            list.push_back(arr[i]);
            permut(arr,size,hashArr,list,ans);
            hashArr[i]=0;
            list.pop_back();
        }
    }
}
 
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    int arr[n];
    cout<<"Enter the array here : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int hashArr[n];
    for(int i=0;i<n;i++){
        hashArr[i]=0;
    }

    vector<vector<int> >ans;
    vector<int>list;

    permut(arr,n-1,hashArr,list,ans);

    for(auto it:ans){
        cout<<"[";
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<"]"<<endl;
    }

return 0;
}