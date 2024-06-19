#include<iostream>
#include<vector>
using namespace std;

int merge(int arr[],int low,int mid,int high){
    vector<int>temp;
    int counter=0;
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

    return counter;
}

int merge_sort(int arr[],int low,int high){
    int counter=0;
    if(low>=high){
        return counter;
    }
    int mid=(low+high)/2;

    counter+=merge_sort(arr,low,mid);
    counter+=merge_sort(arr,mid+1,high);
    counter+=merge(arr,low,mid,high);
    return counter;
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

    int counter=merge_sort(arr,0,n-1);

    cout<<"The Number of Inversions :"<<counter<<endl;
return 0;
}