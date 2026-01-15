class Solution {
public:
    bool solve(string &s, int si, string &p, int pi){
        if(si==s.size() && pi==p.size()){
            return true;
        }
        if(si==s.size() && pi<p.size()){
            while(pi<p.size()){
                if(p[pi]!='*') return false;
                pi++;
            }
            return true;
        }

        if(s[si]==p[pi]||'?'==p[pi]){
            return solve(s,si+1,p,pi+1);
        }
        if(p[pi]=='*'){
            bool casea= solve(s,si,p,pi+1);
            bool caseb=solve(s,si+1,p,pi);
            return casea||caseb;
        }
        return false;
    }
    bool isMatch(string s, string p) {
        return solve(s,0,p,0);
    }
};