#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&nums,int s,int e){
        if(e>=nums.size()){
            return;
        }
        for(int i=s;i<=e;i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        solve(nums,s,e+1);
    }
void print(vector<int>&nums){
    for(int s=0;s<nums.size();s++){
        int e=s;
        solve(nums,s,e);
    }
}
int main(){
    vector<int>nums={1,2,3,4};
    print(nums);
}   