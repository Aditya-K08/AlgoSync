#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    sort(arr.rbegin(),arr.rend());
    int cnt=0;
    int mul=1;
    for(auto x:arr){
        if(x>k) cnt++;
        else if(x*mul<=k){
            mul*=2;
        }else{
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}