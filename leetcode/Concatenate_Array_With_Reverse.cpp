class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> ans = nums;
        vector<int> temp = nums;
        reverse(temp.begin(), temp.end());
        ans.insert(ans.end(), temp.begin(), temp.end());
        return ans;
    }
};