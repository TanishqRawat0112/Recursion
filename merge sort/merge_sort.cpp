#include<iostream>
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
 
int main(){
    int n;
    cout<<"Enter the size of array here : ";
    cin>>n;

    int arr[n];
    cout<<"Enter the unsorted array here : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    merge_sort(arr,0,n-1);

    cout<<"The sorted array would be : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

return 0;
}