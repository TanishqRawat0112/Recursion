//Finding sum of first n natural numbers using global variable

#include<iostream>
using namespace std;

int total=0;

void sum(int n){
    if(n==0){
        return;
    }
    total+=n;
    sum(n-1);
}
 
int main(){
    int n;
    cout<<"Enter the number here : ";
    cin>>n;

    sum(n);

    cout<<"The sum of first "<<n<<" natural numbers are : "<<total<<endl;
return 0;
}