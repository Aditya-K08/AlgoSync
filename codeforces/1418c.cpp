#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    const int INF=1e18;
    vector<vector<int>>dp(n+2,vector<int>(2,INF));
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        if(dp[i][0]!=INF){
            dp[i+1][1]=min(dp[i+1][1],dp[i][0]+arr[i]);
            if(i+1<n)
                dp[i+2][1]=min(dp[i+2][1],dp[i][0]+arr[i]+arr[i+1]);
        }
        if(dp[i][1]!=INF){
            dp[i+1][0]=min(dp[i+1][0],dp[i][1]);
            if(i+1<n)
                dp[i+2][0]=min(dp[i+2][0],dp[i][1]);
        }
    }

    cout<<min(dp[n][0],dp[n][1])<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--) solve();
}