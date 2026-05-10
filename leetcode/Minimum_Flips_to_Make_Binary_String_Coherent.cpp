class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        if(n<3) return 0;
        int cnt1=count(s.begin(),s.end(),'1');
        int cnt0=n-cnt1;
        if(cnt1<2 || cnt1==n || cnt0==n) return 0;
        if(s[0]=='0' && s[n-1]=='0'){
            int rem=cnt0;
            return min(rem,cnt1-1);
        }
        if(s[0]!=s[n-1]){
            //0-1 1-0
            int rem1=cnt1-1;
            int rem2=cnt0;
            return min(rem1,rem2);
        }
        return min(cnt1-2,cnt0);
    }
};