#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    int ans=0;
    for(int &x:a){
        cin>>x;
        ans+=__builtin_popcountll(x);
    }

    for(int bit=0;bit<=60;bit++){
        int cost=(1LL<<bit);
        for(int &x:a){
            if((x&cost)==0 && k>=cost){
                k-=cost;
                ans++;
                x|=cost;
            }
        }
    }
    cout<<ans<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}