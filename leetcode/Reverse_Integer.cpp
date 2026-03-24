class Solution {
public:
    int reverse(int x) {
        bool neg = (x < 0);
        long long val = llabs((long long)x); 

        string s = to_string(val);
        int i = 0, j = s.size() - 1;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        long long rev = stoll(s); 

        if (neg) rev = -rev;
        if (rev < INT_MIN || rev > INT_MAX) return 0; 
        return (int)rev;
    }
};