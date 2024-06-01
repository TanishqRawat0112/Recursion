//Recursive function to reverse an array:

#include<iostream>
using namespace std;

void reverse_array(int array[],int start,int end){
    if(start>end){
        return;
    }
    int temp=array[end];
    array[end]=array[start];
    array[start]=temp;
    reverse_array(array,start+1,end-1);
}
 
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;

    int array[n];
    cout<<"Enter the array : ";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    reverse_array(array,0,n-1);

    cout<<"Reversed Array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
return 0;
}