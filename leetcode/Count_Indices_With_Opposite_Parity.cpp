class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        int odd=0,even=0;
        for(int x:nums){
            if(x&1) odd++;
            else even++;
        }
        vector<int>res(n);
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                odd--;
                res[i]=even;
            }else{
                even--;
                res[i]=odd;
            }
        }
        return res;
    }
};