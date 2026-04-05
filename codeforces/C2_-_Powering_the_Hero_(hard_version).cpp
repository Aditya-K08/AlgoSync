#include <bits/stdc++.h>
using namespace std;
/*
    Author : Zenith 
*/

#define int long long
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)


void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    priority_queue<int>pq;
    int ans=0;
    for(int x:arr){
        if(x){
            pq.push(x);
        }else{
            if(pq.empty()) continue;
            ans+=pq.top();
            pq.pop();
        }
    }
    cout<<ans<<endl;
}

int32_t main(){
    fastio();
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}