class Solution {
public:
    int maxi=1001;
    vector<bool>is_prime=vector<bool>(1001,true);
    vector<int>res;
    int l,r;
    void seive(){
        is_prime[0]=is_prime[1]=false;
        for(int i=2;i*i<maxi;i++){
            if(is_prime[i]){
                for(int j=i*i;j<maxi;j+=i){
                    is_prime[j]=false;
                }
            }
        }
        for(int i=2;i<maxi;i++){
            if(is_prime[i] && i>=l && i<=r){
                res.push_back(i);
            }
        }
    }

    int sumOfPrimesInRange(int n) {
        int orig=n;
        int rev=0;
        while(n){
            int r=n%10;
            rev=rev*10+r;
            n/=10;
        }
        l=min(orig,rev);
        r=max(orig,rev);
        seive();
        return accumulate(res.begin(),res.end(),0);
    }
};