class Solution {
public:
    string res="";
    int ans=0;

    void expand(string &s,int l,int r){
        int n=s.size();

        while(l>=0 && r<n && s[l]==s[r]){
            if(ans < r-l+1){
                ans = r-l+1;
                res = s.substr(l, r-l+1);
            }
            l--;
            r++;
        }
    }

    string longestPalindrome(string s) {
        int n=s.size();
        if(n==0) return "";

        for(int i=0;i<n;i++){
            expand(s,i,i);    
            expand(s,i,i+1); 
        }
        return res;
    }
};