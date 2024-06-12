#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void merge(int arr[],int start,int mid,int end){
    int n=mid-start+1;
    int m=end-mid;
    int arr1[n];
    int arr2[m];
    for(int i=0;i<n;i++){
        arr1[i]=arr[i+start];
    }
    for(int i=0;i<m;i++){
        arr2[i]=arr[i+mid+1];
    }
    int i=0,j=0;
    int index=start;
    while(i<n && j<m){
        if(arr1[i]<=arr2[j]){
            arr[index]=arr1[i];
            i++;
        }
        else{
            arr[index]=arr2[j];
            j++;
        }
        index++;
    }
    while(i<n){
        arr[index]=arr1[i];
        i++;
        index++;
    }
    while(j<m){
        arr[index]=arr2[j];
        j++;
        index++;
    } 
}

void merge_sort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int mid=(start+end)/2;
    merge_sort(arr,start,mid);
    merge_sort(arr,mid+1,end);

    merge(arr,start,mid,end);
}

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
    int arr_size=pow(2,n);
    int final[arr_size];

    for(int i=0;i<arr_size;i++){
        final[i]=ans[i];
    }
    merge_sort(final,0,arr_size-1);

    for(int i=0;i<arr_size;i++){
        cout<<final[i]<<" ";
    }
    cout<<endl;
return 0;
}