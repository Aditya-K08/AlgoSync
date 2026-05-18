#include<bits/stdc++.h>
#include <vector>
using namespace std;
#define int long long
int N=18;
int arr[18];

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>>bonus(n,vector<int>(n,0));
    for(int i=0;i<k;i++){
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        bonus[x][y]=z;
    }
    vector<vector<int>>dp(1<<n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        dp[1<<i][i]=arr[i];
    }

    for(int mask=0;mask<(1<<n);mask++){
        for(int last=0;last<n;last++){
            if(dp[mask][last]==-1) continue;
            for(int nxt=0;nxt<n;nxt++){
                // if that bit is set we exclude it
                if((mask & (1<<nxt))) continue;
                // select that bit 
                int newMask=mask | (1<<nxt);
                // the new mask would have max value of chosen nxt arry element and bonus if exist
                dp[newMask][nxt]=max(dp[newMask][nxt],dp[mask][last]+arr[nxt]+bonus[last][nxt]);
            }
        }
    }


    int ans=0;
    for(int mask=0;mask<(1<<n);mask++){
        int bits=__builtin_popcount(mask);
        if(bits!=m) continue;
        
        if(bits==m){
            for(int last=0;last<n;last++){
                ans=max(ans,dp[mask][last]);
            }
        }
    }
    cout<<ans<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}