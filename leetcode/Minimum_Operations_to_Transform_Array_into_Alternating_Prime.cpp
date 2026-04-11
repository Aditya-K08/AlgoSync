class Solution {
public:
    int mx = 100005;
    vector<bool> is_prime;
    vector<int> primes;
    void sieve(){
        is_prime.assign(mx, true);
        is_prime[0]=is_prime[1]=false;
        for(int i=2;i*i<mx;i++){
            if(is_prime[i]){
                for(int j=i*i;j<mx;j+=i){
                    is_prime[j]=false;
                }
            }
        }

        for(int i=2;i<mx;i++){
            if(is_prime[i]) primes.push_back(i);
        }
    }

    int minOperations(vector<int>& nums) {
        sieve();
        int n=nums.size();
        vector<int>a,b;
        for(int i=0;i<n;i++){
            if(i&1 && is_prime[nums[i]]) b.push_back(nums[i]);
            else if(!(i&1) && !is_prime[nums[i]]) a.push_back(nums[i]);
        }

        int cnt=0;

        for(int x:a){
            auto it = lower_bound(primes.begin(),primes.end(),x);
            if(it!=primes.end()) cnt += (*it - x);
        }

        for(int x:b){
            if(x==2) cnt+=2;
            else cnt++;
        }

        return cnt;
    }
};