class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int prev=nums[0];
        int ans=0;
        n=nums.size();
        int cnt=1;
        for(int i=1;i<n;i++){
            if((long long)prev+1==(long long)nums[i]){
                cnt++;
            }else{
                ans=max(ans,cnt);
                cnt=1;
            }
            prev=nums[i];
        }
        ans=max(ans,cnt);
        return ans;
    }
};