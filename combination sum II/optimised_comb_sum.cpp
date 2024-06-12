#include<iostream>
#include<vector>
using namespace std;

void combination_sum(int arr[],int size,int index, int target,vector<int>&list,vector<vector<int> >&ans){
    if(target==0){
        ans.push_back(list);
        return;
    }
    for(int i=index;i<=size;i++){
        if(i>index && arr[i]==arr[i-1]){
            continue;
        }
        if(arr[i]>target){
            break;
        }
        list.push_back(arr[i]);
        combination_sum(arr,size,i+1,target-arr[i],list,ans);
        list.pop_back();
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
    int target;
    cout<<"Enter the targeted sum here : ";
    cin>>target;

    vector<int >list;
    vector<vector<int> > ans;

    combination_sum(arr,n-1,0,target,list,ans);

    for(vector<int > it: ans){
        for(int i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
return 0;
}