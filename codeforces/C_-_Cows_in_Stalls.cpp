#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
int n,k;
using p=pair<int,int>;
vector<int>arr;
int ans=INT_MAX;

bool feasible(int d){
    int cnt=1;       
    int last=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-last>=d){
            cnt++;
            last=arr[i];
        }
    }
    return cnt >= k;
}
void solve(){
    cin>>n>>k;
    arr.resize(n);
    for(auto &x:arr) cin>>x;
    int lo=0;
    int hi=arr[n-1]-arr[0];
    int ans=0;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(feasible(mid)) {
            lo=mid+1;
            ans=mid;
        }
        else hi=mid-1;
    }
    cout<<ans<<endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}