class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp;
        for(char c:t) mp[c]++;
        for(char c:s) mp[c]--;
        for(auto it:mp){
            if(it.second) return it.first;
        }
        return ' ';
    }
};