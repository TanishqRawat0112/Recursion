//Basic recursive function that is going to print your name a fixed number of times.

#include<iostream>
using namespace std;

void print_name(string s, int n){
    if(n==0){
        return ;
    }
    cout<<s<<endl;
    n--;
    print_name(s,n);
}

int main(){
    int n;
    string name;
    cout<<"Enter the name you want to print : ";
    cin>>name;

    cout<<"Enter the number of times you want to print the name : ";
    cin>>n;

    print_name(name,n);

return 0;
}