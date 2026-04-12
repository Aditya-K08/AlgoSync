class Solution {
public:
    int hammingDistance(int x, int y) {
        if(x>y) return hammingDistance(y,x);
        int cnt=0; 
        while(x>0){
            int b1=x&1;
            int b2=y&1;
            if(b1!=b2) cnt++;
            x>>=1;
            y>>=1;
        }
        cnt+=__builtin_popcount(y);
        return cnt;
    }
};