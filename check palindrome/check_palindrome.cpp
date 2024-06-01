//Using recursion to check whether a string is a palindrome or not.

#include<iostream>
using namespace std;

bool check_palindrome(string s,int start,int end){
    if(s[start]!=s[end]){
        return false;
    }
    if(start>end){
        return true;
    }
    return check_palindrome(s,start+1,end-1);

}
 
int main(){
    string s;
    cout<<"Enter the string here : ";
    cin>>s;
    int n=s.length();
    bool ans=check_palindrome(s,0,n-1);

    if(ans){
        cout<<"The given string is a palindrome.";
    }
    else{
        cout<<"Sorry, but the string is not a palindrome.";
    }
    cout<<endl;
return 0;
}