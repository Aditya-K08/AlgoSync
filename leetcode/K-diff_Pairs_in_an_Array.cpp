class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        int ans=0;
        for(auto &[x,freq]:mp){
            if(k==0){
                if(freq>1) ans++;
            }else{
                if(mp.count(x+k)) ans++;
            }
        }
        return ans;
    }
};