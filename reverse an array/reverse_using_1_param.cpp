//Recursive function in which we are using just one parameter to reverse an array:

#include<iostream>
#include<valarray>
#include <array>
using namespace std;

void reverse_array(int array[],int index){
    if(index>=(array.size()/2)){
        return;
    }
    int last=array.size()/2 - 1 - index;
    int temp=array[index];
    array[index]=array[last];
    array[last]=temp;
    reverse_array(array,index+1);

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
    reverse_array(array,0);

    cout<<"Reversed Array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
return 0;
}