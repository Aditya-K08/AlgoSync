class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        using p=pair<int,int>;
        priority_queue<p,vector<p>,greater<p>>pq;
        for(int i:arr){
            pq.push({abs(x-i),i});
        }
        while(!pq.empty() && k--){
            auto [dist,ele]=pq.top();
            pq.pop();
            ans.push_back(ele);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};