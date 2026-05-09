#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define pyes cout<<"YES\n"
#define pno cout<<"NO\n"
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define int long long
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;
    int l=0,r=0;
    int cnt=0;
    while(l<n && r<m){
        if(a[l]==b[r]) {
            l++;
            r++;
            cnt++;
        }else if(a[l]>b[r]){
            r++;
        }else{
            l++;
        }
    }
    cout<<cnt<<endl;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}