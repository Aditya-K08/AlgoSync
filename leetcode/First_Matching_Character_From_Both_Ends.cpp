class Solution {
public:
    int firstMatchingIndex(string s) {
        int i=0,j=s.size()-1;
    
        while(i<=j){
            if(s[i]==s[j-i]) return i;
            i++;
        }
        return -1;
    }
};