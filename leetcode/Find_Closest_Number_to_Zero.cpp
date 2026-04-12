class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans=INT_MIN;
        int dist=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int x:nums){
            int d=abs(x);
            if(dist>=d){
                dist=d;
                ans=x;
            }
        }
        return ans;
    }
};