//Basic recursive functions to print numbers linearly from n to 1.

#include<iostream>
using namespace std;

//Basic recurion using two parameters
void print_back(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl;
    print_back(n-1);
}
void print_back2(int n,int end){
    if(end>n){
        return;
    }
    print_back2(n,end+1);
    cout<<end<<endl;
}
 
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;

    // print_back(n);
    cout<<"Other way to do that : "<<endl;
    print_back2(n,1);
return 0;
}