class Solution {
public:
    bool validDigit(int n, int x) {
        string s=to_string(n);
        int cnt=count(s.begin(),s.end(),x+'0');
        return (s[0]!=char(x+'0') && cnt);
    }
};