class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(101,0);
        for(int x:nums) freq[x]++;
        int p=0;
        int rem=0;
        for(int i=0;i<101;i++){
            if(freq[i]){
                p+=freq[i]/2;
                rem+=freq[i]%2;
            }
        }
        return {p,rem};
    }
};