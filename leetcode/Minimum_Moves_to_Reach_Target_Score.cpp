class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cnt=0;
        if(target==1) return 0;
        if(target&1){
            target--;
            cnt++;
        }
        while(maxDoubles && target>1){
            if(target&1){
                target--;
                cnt++;
            }else{
                target/=2;
                cnt++;
                maxDoubles--;
            }
        }
        if(target>1) cnt+=target-1;
        return cnt;
    }
};