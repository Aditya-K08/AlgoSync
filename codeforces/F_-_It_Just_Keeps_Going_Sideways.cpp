#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> freq(n + 2, 0), posSum(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        freq[a[i]]++;
        posSum[a[i]] += i;
    }
    vector<int> cnt(n + 2, 0);
    int base = 0;
    int curCnt = 0;
    int curPosSum = 0;
    for (int h = n; h >= 1; h--) {
        curCnt += freq[h];
        curPosSum += posSum[h];
        cnt[h] = curCnt;
        int k = curCnt;
        int finalSum = k * (2 * n - k + 1) / 2;
        base += finalSum - curPosSum;
    }

    int bestGain = 0;
    for (int i = 1; i <= n; i++) {
        int h = a[i];
        int k = cnt[h];
        int gain = i - (n - k + 1);
        bestGain = max(bestGain, gain);
    }
    cout << base + bestGain << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}