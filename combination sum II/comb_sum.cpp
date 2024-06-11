#include<iostream>
#include<vector>
#include<set>
using namespace std;

void combination_sum(int arr[],int size,int index,int target,int sum,vector<int>&list,set<vector<int> >&ans){
    if(index>size || sum>target){
        if(sum==target){
            ans.insert(list);
        }
        return;
    }
    if(sum==target){
        ans.insert(list);
        return;
    }
        list.push_back(arr[index]);
        combination_sum(arr,size,index+1,target,sum+arr[index],list,ans);
        list.pop_back();
    
        combination_sum(arr,size,index+1,target,sum,list,ans);
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
    set<vector<int> > ans;

    combination_sum(arr,n-1,0,target,0,list,ans);

    cout<<"Size of the set is : ";
    cout<<ans.size()<<endl;

    for(vector<int > it: ans){
        for(int i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
return 0;
}