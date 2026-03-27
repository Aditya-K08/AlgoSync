#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
    Author : Zenith
*/
int maxi=200001;
int mod=1e9+7;
vector<int>dp(maxi,0);
void compute(){
    for(int i=0;i<9;i++) dp[i]=2;
    dp[9]=3;
    for(int i=10;i<=maxi;i++){
        dp[i]=dp[i-9]+dp[i-10];
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    int ans=0;
    while(n>0){
        int r= n%10;
        int add =(m+r<9 ? 1 : dp[m+r-10]);
        ans+=add;
        n/=10;
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    compute();
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}