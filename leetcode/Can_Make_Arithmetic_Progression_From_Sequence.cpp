class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int diff=nums[1]-nums[0];
        for(int i=2;i<nums.size();i++){
            int d=nums[i]-nums[i-1];
            if(d!=diff) return false;
        }
        return true;
    }
};