#include<iostream>
#include<vector>
using namespace std;

int counter=0;

void merge(int arr[],int low,int mid,int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;

    while(left<=mid && right<=high){
        if(arr[left]>arr[right]){
            counter+=mid-left+1;
            temp.push_back(arr[right]);
            right++;
        }
        else{
            temp.push_back(arr[left]);
            left++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    //arranging the original array according to the sort:
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void merge_sort(int arr[],int low,int high){
    if(low>=high){
        return;
    }
    int mid=(low+high)/2;

    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
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

    merge_sort(arr,0,n-1);

    cout<<"The Number of Inversions :"<<counter<<endl;
return 0;
}