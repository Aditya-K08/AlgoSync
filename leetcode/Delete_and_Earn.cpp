class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;
        }
        vector<int>dp(mx+1,0);
        if(mx>=1) dp[1]=1*mp[1];
        for(int i=2;i<=mx;i++){
            dp[i]=max(dp[i-1],dp[i-2]+i*mp[i]);
        }
        return dp[mx];
    }
};