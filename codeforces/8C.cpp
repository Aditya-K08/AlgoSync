#include<bits/stdc++.h>
#include <vector>
using namespace std;
#define int long long

int xs,ys;
int x[25],y[25];

int dist(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

void solve(){
    cin>>xs>>ys;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    vector<int>dp(1<<n,1e18);
    vector<int>par(1<<n,-1);
    dp[0]=0;
    for(int mask=0;mask<(1<<n);mask++){
        if(dp[mask]==1e18) continue;
        int first=-1;
        for(int i=0;i<n;i++){
            if(!(mask&(1<<i))){
                first=i;
                break;
            }
        }
        if(first==-1) continue;
        int newMask=mask|(1<<first);
        int cost=2*dist(xs,ys,x[first],y[first]);
        if(dp[newMask]>dp[mask]+cost){
            dp[newMask]=dp[mask]+cost;
            par[newMask]=mask;
        }

        for(int j=first+1;j<n;j++){
            if(mask&(1<<j)) continue;

            int nmask=mask|(1<<first)|(1<<j);
            int cur=dist(xs,ys,x[first],y[first])+
                    dist(x[first],y[first],x[j],y[j])+
                    dist(x[j],y[j],xs,ys);

            if(dp[nmask]>dp[mask]+cur){
                dp[nmask]=dp[mask]+cur;
                par[nmask]=mask;
            }
        }
    }
    cout<<dp[(1<<n)-1]<<"\n";
    vector<int>path;
    int mask=(1<<n)-1;
    while(mask){
        int pmask=par[mask];
        int diff=mask^pmask;
        path.push_back(0);
        for(int i=0;i<n;i++){
            if(diff&(1<<i)){
                path.push_back(i+1);
            }
        }
        mask=pmask;
    }
    path.push_back(0);
    reverse(path.begin(),path.end());
    for(int x:path){
        cout<<x<<" ";
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}