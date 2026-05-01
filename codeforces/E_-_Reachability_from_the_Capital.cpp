#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, m, s;
vector<int> g[N];
bool vis[N];
vector<int> order;

void dfsOrder(int u) {
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v]) dfsOrder(v);
    }
    order.push_back(u);
}

void dfs(int u) {
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v]) dfs(v);
    }
}

void solve() {
    cin >> n >> m >> s;
    s--;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfsOrder(i);
    }
    memset(vis, false, sizeof(vis));
    dfs(s);
    reverse(order.begin(), order.end());
    int ans = 0;
    for (int u : order) {
        if (!vis[u]) {
            ans++;
            dfs(u);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}