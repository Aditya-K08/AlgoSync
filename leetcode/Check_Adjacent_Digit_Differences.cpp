class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int diff=0;
        for(int i=1;i<s.size();i++){
            if(abs((s[i]-'0') - (s[i-1]-'0'))>2) return false;
        }
        return true;
    }
};