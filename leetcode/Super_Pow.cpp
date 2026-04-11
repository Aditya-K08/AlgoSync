class Solution {
public:
    int mod = 1337;

    int binPow(int a,int b){
        int res=1;
        a%=mod;
        while(b){
            if(b&1) res=res*a%mod;
            a=a*a%mod;
            b>>=1;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        int res=1;
        for(int x:b){
            res=binPow(res,10)*binPow(a,x)%mod;
        }
        return res;
    }
};