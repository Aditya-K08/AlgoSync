class Solution {
public:
    long long mod=1e9+7;
    long long binpow(long long a,long long p){
        long long res=1;
        a%=mod;
        while(p){
            if(p&1) res=(res*a)%mod;
            a=(a*a)%mod;
            p>>=1;
        }
        return res;
    }

    int minNonZeroProduct(int n) {
        long long mx=(1LL<<n)-1;
        long long second=mx-1;
        long long exp=(1LL<<(n-1))-1;
        mx%=mod;
        return (binpow(second,exp)*mx)%mod;
    }
};