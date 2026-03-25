#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    int cnt=0;
    vector<int>req;
    for(int i=1;i<=n;i++){
        int x=arr[i];
        cnt+=__builtin_ctzll(x);
        int r=__builtin_ctzll(i);
        req.push_back(r);
    }
    if(cnt>=n){
        cout<<0<<endl;
        return;
    }
    sort(req.rbegin(),req.rend());
    int required = n-cnt;
    vector<int>prefix(n+1,0);
    for(int i=0;i<(int)req.size();i++){
        prefix[i+1]=prefix[i]+req[i];
    }
    if(prefix[n]<required){
        cout<<-1<<endl;
    }
    else{
        int x=lower_bound(prefix.begin(),prefix.end(),required)-prefix.begin();
        cout<<x<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}