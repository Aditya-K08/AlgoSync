#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int eve=0,odd=0;
    for(int x:arr){
        if(x&1) odd++;
        else eve++;
    }
    int sum=accumulate(arr.begin(),arr.end(),0ll);
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        if(l==0){
            int extra=eve*r;
            sum+=extra;
            cout<<sum<<endl;
            if(r&1){
                odd+=eve;
                eve=0;
            }
        }else{
            int extra=odd*r;
            sum+=extra;
            cout<<sum<<endl;
            if(r&1){
                eve+=odd;
                odd=0;
            }
        }
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