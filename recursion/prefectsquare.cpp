class Solution {
public:
    int solve(int n){
        if(n==0) return 1;
        if(n<0) return 0;
        int i=1;
        int ans=INT_MAX;
        int end=sqrt(n);
        while(i<=end){
            int sqr=i*i;
            int count=1+solve(n-sqr);
            if(count<ans){
                ans=count;
            }
            i++;
        }
        return ans;
    }
    int numSquares(int n) {
        return solve(n)-1;
    }
};