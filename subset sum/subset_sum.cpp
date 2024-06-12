#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void subset_sum(int arr[],int size,int index,int sum,vector<int>&ans){
    if(index>size){
        ans.push_back(sum);
        return;
    }
    //picking the element:
    subset_sum(arr,size,index+1,sum+arr[index],ans);

    //not picking the element:
    subset_sum(arr,size,index+1,sum,ans);
}
 
int main(){
    int n;
    cout<<"Enter the size of the array here : ";
    cin>>n;

    int arr[n];
    cout<<"Enter the array here : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int>ans;

    subset_sum(arr,n-1,0,0,ans);

    // ans.sort(ans.begin(),ans.end());

    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
return 0;
}