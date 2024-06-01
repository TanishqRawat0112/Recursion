//getting the sum of first n natural numbers using recursion
//Without any global variable of pssing parameter;

#include<iostream>
using namespace std;

int sum_of_n(int n){
    if(n==0){
        return 0;
    }
    return n + sum_of_n(n-1);
}
 
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;

    int sum=sum_of_n(n);

    cout<<"Sum of first "<<n<<" numbers : "<<sum<<endl; 
return 0;
}