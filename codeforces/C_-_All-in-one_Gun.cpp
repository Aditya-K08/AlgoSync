#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
    Author : Zenith
*/
void solve(){
    int n,h,k;
    cin>>n>>h>>k;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int sum = accumulate(arr.begin(), arr.end(), 0LL);
    int r = (h - 1) / sum;
    int rem = h - r * sum; 
    vector<int>pref(n+1,0), prefmin(n+1,LLONG_MAX), suffmax(n+2,LLONG_MIN);
    for(int i=0;i<n;i++){
        pref[i+1] = pref[i] + arr[i];
        prefmin[i+1] = min(prefmin[i], arr[i]);
    }
    for(int i=n-1;i>=0;i--){
        suffmax[i+1] = max(suffmax[i+2], arr[i]);
    }
    int need = n;
    for(int i=1;i<=n;i++){
        int best = pref[i];
        if(i < n){
            best += max(0LL, suffmax[i+1] - prefmin[i]);
        }
        if(best >= rem){
            need = i;
            break;
        }
    }
    int ans = r * (n + k) + need;
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}