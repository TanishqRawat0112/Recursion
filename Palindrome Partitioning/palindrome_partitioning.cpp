#include<iostream>
#include<vector>
using namespace std;

bool isPalindrome(string s,int left,int right){
    while(left<=right){
        if(s[left]!=s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void partition(string s,int size,int index,vector<string>&list,vector<vector<string> >&ans){
    if(index==size){
        ans.push_back(list);
        return;
    }
    for(int i=index;i<size;i++){
        if(isPalindrome(s,index,i)){
            string temp="";
            for(int j=index;j<=i;j++){
                temp+=s[j];
            }
            list.push_back(temp);
            partition(s,size,i+1,list,ans);
            list.pop_back();
        }
    }
}
 
int main(){
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    int n=s.size();
    vector<string>list;
    vector<vector<string> >ans;

    partition(s,n,0,list,ans);

    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
return 0;
}