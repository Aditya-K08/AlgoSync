class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int res=1;
        if(n==1) return true;
        string r2=to_string(n);
        sort(r2.begin(),r2.end());
        for(int i=0;i<31;i++){
            int r1=(1<<i);
            string rr=to_string(r1);
            sort(rr.begin(),rr.end());
            if(rr==r2) return true;
        }
        //cout<<r1<<" "<<r2;
        return false;
    }
};