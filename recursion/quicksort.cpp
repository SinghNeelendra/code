#include<bits/stdc++.h>
using namespace std;

int parti(int nums[],int s,int e){
    int p=nums[s];
    int pindex=s;
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(nums[i]<p){
            count++;
        }
    }
    int rindex=s+count;
    swap(nums[pindex],nums[rindex]);
    pindex=rindex;
    int i=s,j=e;
    while(i<pindex && j>pindex){
        while(nums[i]<p){
            i++;
        }
        while(nums[j]>p){
            j--;
        }
        if(i<pindex && j>pindex){
            swap(nums[i],nums[j]);
        }
    }
    return pindex;

}


void qsort(int nums[],int s,int e){
    if(s>=e){
        return;
    }
    int p=parti(nums,s,e);
    qsort(nums,s,p-1);
    qsort(nums,p+1,e);
}


int main(){
    int nums[]={1,4,23,45,3,76,45,87,2};
    int s=0,n=9;
    int e=n-1;
    qsort(nums,s,e);
    for(int i=0;i<=e;i++){
        cout<<nums[i]<<" ";
    }

}   