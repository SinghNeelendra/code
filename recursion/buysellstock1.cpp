class Solution {
public:
    void solve(vector<int>&p,int i,int &mini,int &maxipf){
        if(i>=p.size())return ;
        if(p[i]<mini)mini=p[i];
        int todaypf=p[i]-mini;
        if(todaypf>maxipf)maxipf=todaypf;
        solve(p,i+1,mini,maxipf);
    }
    int maxProfit(vector<int>& p) {
        bool isrev=is_sorted(p.begin(), p.end(), std::greater<int>());
        if(isrev) return 0;
        else{
            int mini=INT_MAX;
            int maxipf=0;
            solve(p,0,mini,maxipf);
            return maxipf;
        }
    }
};