#include<iostream>
using namespace std;

void quick_sort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int pivot=start;
    int i=pivot+1;
    int j=end;
    int partition;
    while(true){
        while(i<=end){
            if(arr[i]>arr[pivot]){
                break;
            }
            i++;
        }
        while(j>pivot){
            if(arr[j]<arr[pivot]){
                break;
            }
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
        else{
            if(j<pivot){
                partition=pivot;
                break;
            }
            swap(arr[j],arr[pivot]);
            break;
        }
    }
    partition=j;
    quick_sort(arr,start,partition-1);
    quick_sort(arr,partition+1,end);

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