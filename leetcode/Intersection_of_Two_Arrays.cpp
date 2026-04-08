class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>arr;
        set<int>st(nums1.begin(),nums1.end());
        for(int x:nums2) if(st.count(x)) arr.insert(x);
        vector<int>ans(arr.begin(),arr.end());
        return ans;
    }
};