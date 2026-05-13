#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<string> g(n);
    for(int i=0;i<n;i++) cin>>g[i];
    vector<vector<int>> ps(n+1, vector<int>(m+1, 0));
    int total = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int val = (g[i-1][j-1]=='g');
            total += val;
            ps[i][j] = val + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
        }
    }

    auto get = [&](int x1,int y1,int x2,int y2){
        if(x1>x2 || y1>y2) return 0;
        return ps[x2][y2] - ps[x1-1][y2] - ps[x2][y1-1] + ps[x1-1][y1-1];
    };

    int best = INT_MAX;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i-1][j-1] != '.') continue;
            int x1 = max(1, i-k+1);
            int y1 = max(1, j-k+1);
            int x2 = min(n, i+k-1);
            int y2 = min(m, j+k-1);
            best = min(best, get(x1,y1,x2,y2));
        }
    }
    cout << total - best << '\n';
}

signed main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
}