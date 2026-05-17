class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<unsigned int>dp(amount+1);
        dp[0]=1;
        for(int coin:coins){
            for(int s=coin;s<=amount;s++){
                dp[s]+=dp[s-coin];
            }
        }
        return dp[amount];
    }
};