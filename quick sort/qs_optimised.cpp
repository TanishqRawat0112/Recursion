#include<iostream>
using namespace std;

int func(int arr[],int start,int end){
    int pivot=arr[start];
    int i=start;
    int j=end;
    while(i<j){
        while(arr[i]<=pivot && i<end){
            i++;
        }
        while(arr[j]>pivot && j>start){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[start],arr[j]);
    return j;
}

void quick_sort(int arr[],int start,int end){
    if(start<end){
        int partition=func(arr,start,end);
        quick_sort(arr,start,partition-1);
        quick_sort(arr,partition+1,end);
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

    quick_sort(arr,0,n-1);

    cout<<"Your sorted array is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
return 0;
}