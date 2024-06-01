//Basic recursive functions to print numbers linearly from n to 1.

#include<iostream>
using namespace std;

//Basic recurion using two parameters
void print_back(int n, int end){
    if(n==end){
        return;
    }
    cout<<n<<endl;
    n--;
    print_back(n,end);
}
void print_back2(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl;
    print_back2(n-1);

}
 
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;

    // print_back(n,0);
    cout<<"Other way to do that : "<<endl;
    print_back2(n);
return 0;
}