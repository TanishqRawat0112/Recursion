//Finding the sum of first n natural numbers using two parameters n a recursive function.

#include<iostream>
using namespace std;

int sum2(int n,int sum){
    if(n==0){
        return sum;
    }
    return sum2(n-1,sum+n);
};
 
int main(){
    int n;
    cout<<"Enter the number here : ";
    cin>>n;

    int ans=sum2(n,0);
    cout<<"The sum is : "<<ans<<endl;
return 0;
}