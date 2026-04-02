class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        int ans=0;
        unordered_map<char,int>mp;
        while(i<n){
            while(mp[s[i]]==1){
                mp[s[j]]--;
                if(mp[s[j]]==0) mp.erase(s[j]);
                j++;   
            }
            ans=max(ans,i-j+1);
            mp[s[i]]++;
            i++;
        }
        return ans;
    }
};