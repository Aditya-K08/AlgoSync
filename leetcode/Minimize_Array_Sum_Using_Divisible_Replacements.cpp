class Solution {
public:
    unordered_map<int,vector<int>> fac;
    void factorise(int n){
        vector<int> res;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                res.push_back(i);
                if(i*i!=n){
                    res.push_back(n/i);
                }
            }
        }
        sort(res.begin(),res.end());
        fac[n]=res;
    }

    long long minArraySum(vector<int>& nums) {
        int n=nums.size();
        if(count(nums.begin(),nums.end(),1)){
            return n;
        }
        set<int> st(nums.begin(),nums.end());
        for(int x:st){
            factorise(x);
        }
        for(int &x:nums){
            for(int v:fac[x]){
                if(st.count(v)){
                    x=v;
                    break;
                }
            }
        }
        return accumulate(nums.begin(),nums.end(),0LL);
    }
};