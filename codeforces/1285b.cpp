#include<bits/stdc++.h>
using namespace std;
#define int long long

int kadane(vector<int>&a, int l, int r){
    int curr=a[l], maxi=a[l];
    for(int i=l+1;i<=r;i++){
        curr=max(a[i], curr+a[i]);
        maxi=max(maxi, curr);
    }
    return maxi;
}

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto &x:a) cin>>x;
    int sum=accumulate(a.begin(),a.end(),0LL);
    int left = kadane(a,0,n-2);
    int right = kadane(a,1,n-1);
    int maxi = max(left, right);
    if(sum > maxi) cout<<"YES\n";
    else cout<<"NO\n";
}

int32_t main(){
    int t; cin>>t;
    while(t--) solve();
}