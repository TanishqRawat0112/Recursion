//Using Recurion  to calculate the fibonacci number

#include<iostream>
using namespace std;

int fibonacci(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}
 
int main(){
    int n;
    cout<<"Enter the number here : ";
    cin>>n;

    cout<<"The "<<n<<"th fibonacci number is : "<<fibonacci(n)<<endl;
return 0;
}