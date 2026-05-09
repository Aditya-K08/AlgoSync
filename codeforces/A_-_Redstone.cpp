#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define pyes cout<<"YES\n"
#define pno cout<<"NO\n"

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    unordered_map<int,int>mp;
    for(int x:arr) mp[x]++;
    for(auto it:mp){
        if(it.second>=2){
            pyes;
            return;
        }
    }
    pno;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}