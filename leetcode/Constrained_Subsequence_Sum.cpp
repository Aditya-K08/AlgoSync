class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(nums.begin(),nums.end());
        deque<int>dq;
        for(int i=0;i<n;i++){
            if(!dq.empty()) dp[i]=max(dp[i],dp[i]+dp[dq.front()]);
            while(!dq.empty() && dp[i]>=dp[dq.back()]) dq.pop_back();
            dq.push_back(i);
            if(!dq.empty() && dq.front()<=i-k) dq.pop_front();
        }
        return *max_element(dp.begin(),dp.end());
    }
};