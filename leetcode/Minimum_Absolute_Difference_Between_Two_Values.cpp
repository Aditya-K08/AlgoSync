class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        vector<vector<int>>arr(3,vector<int>());
        for(int i=0;i<nums.size();i++){
            arr[nums[i]].push_back(i);
        }
        if(arr[1].empty() || arr[2].empty()) return -1;
        unordered_map<int,int>mp;
        int ans=INT_MAX;
        for(int i=0;i<arr[1].size();i++){
            for(int j=0;j<arr[2].size();j++){
                int dist=abs(arr[1][i]-arr[2][j]);
                ans=min(dist,ans);
                mp[dist]++;
            }
        }
        return ans;
    }
};