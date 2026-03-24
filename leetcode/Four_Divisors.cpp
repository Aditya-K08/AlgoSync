class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int x:nums){
            int cnt=0,sum=0;
            for(int i=1;i*i<=x;i++){
                if(x%i==0){
                    cout<<i<<" ";
                    cnt++;
                    sum+=i;
                    if(i*i!=x){
                        cnt++;
                        sum+=x/i;
                    }
                }
            }
            if(cnt==4){
                ans+=sum;
            }
        }
        return ans;
    }
};