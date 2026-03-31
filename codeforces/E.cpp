#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<vector<double>> arr(n, vector<double>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];

    vector<vector<double>>dp(1<<n,vector<double>(n,0));
    for(int i=0;i<n;i++)
        dp[1<<i][i]=1.0;

    for(int mask=0; mask<(1<<n);mask++){
        int k=__builtin_popcount(mask);
        if(k<=1) continue;
        double total=k*(k-1)/2.0;
        for(int a=0;a<n;a++){
            if(!((mask>>a)&1)) continue;
            for(int b=a+1;b<n;b++){
                if(!((mask>>b)&1)) continue;
                dp[mask][a] += (1.0/total)*arr[a][b]*dp[mask^(1<<b)][a];
                dp[mask][b] += (1.0/total)*arr[b][a]*dp[mask^(1<<a)][b];
                for(int i=0;i<n;i++){
                    if(!((mask>>i)&1)) continue;
                    if(i==a || i==b) continue;
                    dp[mask][i] += (1.0/total)*arr[a][b]*dp[mask^(1<<b)][i];
                    dp[mask][i] += (1.0/total)*arr[b][a]*dp[mask^(1<<a)][i];
                }
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<fixed<<setprecision(6)<<dp[(1<<n)-1][i]<<" ";
    cout<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}