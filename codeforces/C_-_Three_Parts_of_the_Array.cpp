#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    unordered_map<int,int>mp;
    int sum=0;
    for(int i=0;i<n;i++){
        int x=arr[i];
        sum+=x;
        mp[sum]=i;
    }
    int rsum=0;
    int maxi=0;
    for(int i=n-1;i>=0;i--){
        rsum+=arr[i];
        if(mp.count(rsum) && mp[rsum]<i){
            maxi=max(rsum,maxi);
        }
    }
    cout<<maxi<<endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}