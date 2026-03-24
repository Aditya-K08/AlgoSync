#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> parent, sz;
    DSU(int n) :n(n),parent(n),sz(n,1){
        iota(parent.begin(),parent.end(), 0);
    }
    int find(int x) {
        if (parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<string>s(n);
    for (int i=0;i<n;i++) cin>>s[i];

    for (int i=0;i<n;i++) {
        if (s[i][i]!='1') {
            cout<<"No\n";
            return;
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i!=j && s[i][j]=='1' && s[j][i]=='1') {
                cout<<"No\n";
                return;
            }
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (s[i][j]=='1') {
                for (int k=0;k<n;k++) {
                    if (s[j][k]=='1' && s[i][k]=='0') {
                        cout<<"No\n";
                        return;
                    }
                }
            }
        }
    }
    vector<pair<int,int>> edges;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++){
            if (i==j || s[i][j]=='0') continue;
            bool flag = true;
            for (int k=0;k<n;k++) {
                if (k==i || k==j) continue;
                if (s[i][k]=='1' && s[k][j]=='1') {
                    flag = false;
                    break;
                }
            }
            if (flag) edges.push_back({i,j});
        }
    }
    if (edges.size()!=n-1) {
        cout<<"No\n";
        return;
    }

    DSU dsu(n);
    for(auto [u,v]:edges) dsu.unite(u, v);

    int root=dsu.find(0);
    for (int i=1;i<n;i++) {
        if (dsu.find(i) != root) {
            cout<< "No\n";
            return;
        }
    }
    cout<<"Yes\n";
    for (auto [u, v] : edges) {
        cout <<u+1<<' '<<v+1<< '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}