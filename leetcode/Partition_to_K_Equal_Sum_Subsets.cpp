class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(1<<n,-1);
        int sum=accumulate(nums.begin(),nums.end(),0);
        int tar=sum/k;
        if(sum%k) return false;
        dp[0]=0;
        for(int mask=0;mask<(1<<n);mask++){
            if(dp[mask]==-1) continue;
            for(int i=0;i<n;i++){
                if((mask>>i)&1) continue;
                if(dp[mask]+nums[i]>tar) continue;
                dp[mask|(1<<i)]=(dp[mask]+nums[i])%tar;
            }
        }
        return dp[(1<<n)-1]==0;
    }
};