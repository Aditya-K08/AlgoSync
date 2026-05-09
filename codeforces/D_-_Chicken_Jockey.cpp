#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define pyes cout<<"YES\n"
#define pno cout<<"NO\n"
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    vector<int>dp(n+1,0);
    dp[1]=arr[0];
    for(int i=1;i<n;i++){
        dp[i+1]=min(dp[i]+arr[i]-1,dp[i-1]+arr[i-1]+max(arr[i]-i,0ll));
    }
    cout<<dp[n]<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}