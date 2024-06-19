//Optimised Version of finding the Kth permutation sequence without using recursion:

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string getPermutation(int n,int k){
    vector<int>numbers;
    int fact=1;
    for(int i=1;i<n;i++){
        fact*=i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans="";
    k=k-1;

    while (true){
        ans+=to_string(numbers[k/fact]);
        numbers.erase(numbers.begin()+k/fact);
        if(numbers.size()==0){
            break;
        }
        k%=fact;
        fact/=numbers.size();
    }
    return ans;
}
 
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;

    int k;
    cout<<"Enter the number of sequence : ";
    cin>>k;

    string final=getPermutation(n,k);

    cout<<"The Desired Sequence is : "<<endl;
    cout<<final<<endl;

return 0;
}