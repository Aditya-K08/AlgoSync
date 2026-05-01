#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> cnt(m, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i] % m]++;
    }

    int need = n / m;
    set<int> deficient;

    for (int r = 0; r < m; r++) {
        if (cnt[r] < need) {
            deficient.insert(r);
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int r = a[i] % m;

        if (cnt[r] <= need) continue;

        auto it = deficient.lower_bound(r);
        if (it == deficient.end()) {
            it = deficient.begin();
        }

        int target = *it;
        int add = (target - r + m) % m;

        a[i] += add;
        ans += add;

        cnt[r]--;
        cnt[target]++;

        if (cnt[target] == need) {
            deficient.erase(target);
        }
    }

    cout << ans << '\n';
    for (int x : a) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}