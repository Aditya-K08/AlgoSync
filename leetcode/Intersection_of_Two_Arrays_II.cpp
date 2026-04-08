class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(int x:nums1) mp[x]++;
        vector<int>ans;
        for(int x:nums2){
            if(mp.count(x)){
                mp[x]--;
                if(mp[x]==0) mp.erase(x);
                ans.push_back(x);
            }
        }
        return ans;
    }
};