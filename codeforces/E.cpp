#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    vector<int>pref(n+1,0);
    sort(arr.rbegin(),arr.rend());
    for(int i=1;i<=n;i++){
        pref[i]=pref[i-1]+arr[i-1];
    }
    // cout<<q<<endl;
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        auto y=lower_bound(pref.begin(),pref.end(),x);
        if(y==pref.end()){
            cout<<-1<<endl;
        }
        else cout<<y-pref.begin()<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}