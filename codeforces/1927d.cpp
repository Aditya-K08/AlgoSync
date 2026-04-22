#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto &x:a) cin>>x;
    vector<int>pref(n, -1);
    for(int i=n-2;i>=0;i--){
        if(a[i]!=a[i+1]) pref[i]=i+1;
        else pref[i]=pref[i+1];
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--; r--; 
        if(pref[l]!=-1 && pref[l]<=r){
            cout<<l+1<<" "<<pref[l]+1<<"\n";
        }else{
            cout<<"-1 -1\n";
        }
    }
    cout<<"\n";
}
int32_t main(){
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}