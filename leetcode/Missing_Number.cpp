class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(n+1,1);
        for(int x:nums) freq[x]--;
        for(int i=0;i<=n;i++) if(freq[i]) return i;
        return -1;
    }
};