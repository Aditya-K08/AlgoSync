class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt=0;
        for(int x:nums){
            while(x>0){
                int r=x%10;
                if(r==digit) cnt++;
                x/=10;
            }
        }
        return cnt;
    }
};