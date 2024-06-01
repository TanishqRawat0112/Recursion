#include <iostream>
using namespace std;

void print_num(int count){
    if(count<1){
        return;
    }
    count--;
    print_num(count);
    cout<<count+1<<endl;
}

int main(){
    int n;
    cout<<"Enter the number :";
    cin>>n;

    print_num(n);

    return 0;
}