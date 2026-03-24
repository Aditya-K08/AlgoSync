class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int x:nums){
            int cnt=2,sum=x+1;
            for(int i=2;i*i<=x;i++){
                if(x%i==0){
                    cnt++;
                    sum+=i;
                    cout<<x/i<<" "<<x<<endl;
                    if(x/i!=i){
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