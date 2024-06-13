#include<iostream>
#include<vector>
using namespace std;

void subset_sum(int arr[],int size,int index,int sum,vector<int>&ans){
    if(index>size){
        return;
    }
    for(int i=index;i<=size;i++){
        if(i>index && arr[i]==arr[i-1]){
            continue;
        }
        ans.push_back(sum+arr[i]);
        subset_sum(arr,size,i+1,sum+arr[i],ans);
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

    vector<int>ans;

    subset_sum(arr,n-1,0,0,ans);
    ans.push_back(0);
    sort(ans.begin(),ans.end());

    for(int it:ans){
        cout<<it<<" ";
    }
    cout<<endl;

return 0;
}