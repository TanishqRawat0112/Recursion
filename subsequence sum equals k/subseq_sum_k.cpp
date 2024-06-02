#include<iostream>
#include<vector>
using namespace std;
 //Recursive function when the array contains only positives
void subsequence_sum_equals_k(vector<int>&arr,int index,int size,int k,int sum,vector<vector<int> >&answer,vector<int>&list){
    if(sum>=k || index==size){
        if(sum==k){
            answer.push_back(list);
        }
        return;
    }
    list.push_back(arr[index]);
    subsequence_sum_equals_k(arr,index+1,size,k,sum+arr[index],answer,list);
    list.pop_back();
    subsequence_sum_equals_k(arr,index+1,size,k,sum,answer,list); 
}

//recursive function when the array contains positives,zeroes and negatives
void subsequence_sum_equals_k2(vector<int>&arr,int index,int size,int k,int sum,vector<vector<int> >&answer,vector<int>&list){
    if(index==size){
        if(sum==k){
            answer.push_back(list);
        }
        return;
    }
    list.push_back(arr[index]);
    subsequence_sum_equals_k2(arr,index+1,size,k,sum+arr[index],answer,list);
    list.pop_back();
    subsequence_sum_equals_k2(arr,index+1,size,k,sum,answer,list); 
}
//Function to find only one subsequence whose sum equals k.
void only_subsequence_sum_equals_k(vector<int>&arr,int index,int size,int k,int sum,vector<vector<int> >&answer,vector<int>&list){
    if(index==size){  
        if(answer.size()==0){
            if(sum==k){
                answer.push_back(list);
            }
        }
        return;
    }
    list.push_back(arr[index]);
    only_subsequence_sum_equals_k(arr,index+1,size,k,sum+arr[index],answer,list);
    list.pop_back();
    only_subsequence_sum_equals_k(arr,index+1,size,k,sum,answer,list); 
}

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    vector<int>arr;
    int inp;
    cout<<"Enter the array here : ";
    for(int i=0;i<n;i++){
        cin>>inp;
        arr.push_back(inp);
    }

    int k;
    cout<<"Enter the number to which the sum should be equal : ";\
    cin>>k;

    vector<int>list;
    vector<vector<int> > answer;
    only_subsequence_sum_equals_k(arr,0,n,k,0,answer,list);

    for(auto it:answer){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }

return 0;
}