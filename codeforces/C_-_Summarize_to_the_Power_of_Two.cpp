#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;

    map<int,int>mp;
    for(auto x:arr) mp[x]++;

    int cnt=0;

    for(int x:arr){
        bool ok=false;
        for(int i=1;i<32;i++){
            int tar=(1LL<<i);
            if(tar<x) continue;
            int rem=tar-x;
            if(rem==x){
                if(mp[x]>=2){
                    ok=true;
                    break;
                }
            }
            else if(mp.count(rem)){
                ok=true;
                break;
            }
        }
        if(!ok) cnt++;
    }

    cout<<cnt<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}