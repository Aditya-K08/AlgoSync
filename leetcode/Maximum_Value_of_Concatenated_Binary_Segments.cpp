class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        a %= MOD;
        while (b > 0) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        vector<pair<int,int>> segments;

        for (int i = 0; i < n; i++) {
            segments.push_back({nums1[i], nums0[i]});
        }

        auto type = [&](const pair<int,int>& p) {
            int ones = p.first, zeros = p.second;
            if (ones > 0 && zeros == 0) return 0; 
            if (ones > 0 && zeros > 0)  return 1; 
            return 2;                             
        };

        sort(segments.begin(), segments.end(), [&](const auto& a, const auto& b) {
            int ta = type(a), tb = type(b);
            if (ta != tb) return ta < tb;

            if (ta == 0 || ta == 2) {
                return false; 
            }
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });

        long long ans = 0;

        for (auto &[ones, zeros] : segments) {
            long long segVal = ((modPow(2, ones) - 1 + MOD) % MOD * modPow(2, zeros)) % MOD;
            ans = (ans * modPow(2, ones + zeros) + segVal) % MOD;
        }

        return (int)ans;
    }
};