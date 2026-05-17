class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>pref(n+1,0),suff(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=max(pref[i],nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            suff[i]=max(suff[i+1],nums[i]);
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            if(i==0 && i==n-1) res.push_back(nums[i]);
            else{
                if(pref[i]<nums[i] || nums[i]>suff[i+1]) res.push_back(nums[i]);
            }
        }
        return res;
    }
};