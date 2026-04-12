class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            int sum=nums[i];
            int j=i+1;
            while(j<n && nums[j-1]<nums[j]){
                sum+=nums[j++];
            }
            j=i;
            maxi=max(sum,maxi);
        }
        return maxi;
    }
};