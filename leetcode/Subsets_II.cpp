class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        for(int mask=0;mask<(1<<n);mask++){
            vector<int>subset;
            bool valid=true;
            for(int i=0;i<n;i++){
                if(mask &(1<<i)) {
                    if(i>0 && nums[i]==nums[i-1] && !(mask&(1<<(i-1)))){
                        valid=false;
                        break;
                    }
                    subset.push_back(nums[i]);
                }
            }
            if(valid) ans.push_back(subset);
        }
        return ans;
    }
};