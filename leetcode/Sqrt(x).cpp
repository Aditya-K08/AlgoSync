class Solution {
public:
    int mySqrt(int x) {
        vector<int>arr={x};
        int ans=0;
        for(long long i=1;i*i<=x;i++){
            auto it=lower_bound(arr.begin(),arr.end(),i*i);
            if(it==arr.end()) return ans;
            else ans=i;
        }
        return ans;
    }
};