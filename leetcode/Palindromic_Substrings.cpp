class Solution {
public:
    int cnt=0;
    int n;
    void expand(string s,int l,int r){
        while(l>=0 && r<n && s[l]==s[r]){
            cnt++;
            l--;
            r++;
        }
    }
    int countSubstrings(string s) {
        n=s.size();
        
        for(int i=0;i<n;i++){
            expand(s,i,i);
            expand(s,i,i+1);
        }
        return cnt;
    }
};