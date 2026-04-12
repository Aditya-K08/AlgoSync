class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        vector<int>freq(101,0);
        for(int x:nums) freq[x]++;
        for(int x:nums){
            if(!(x&1) && freq[x]==1) return x;
        }
        return -1;
    }
};