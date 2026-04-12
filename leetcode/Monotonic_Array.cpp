class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        bool inc=true;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]) {
                inc=false;
                break;
            }
        }
        bool dec=true;
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]) {
                dec=false;
                break;
            }
        }
        if(inc && dec) return true;
        int ans = inc^dec;
        return ans;
    }
};