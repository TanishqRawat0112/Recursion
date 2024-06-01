//Two basic recursive methods to print numbers linearly from 1 to n.

#include<iostream>
using namespace std;

void print_linearly1(int start,int n){
    if(start>n){
        return;
    }
    cout<<start<<endl;
    start++;
    print_linearly1(start,n);
}

void print_linearly2(int n){
    if(n<1){
        return;
    }
    print_linearly2(n-1);
    cout<<n<<endl;
}
 
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;

    // print_linearly1(1,n);
    cout<<"Other way to achieve that : "<<endl;
    print_linearly2(n);
return 0;
}