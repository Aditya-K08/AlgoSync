#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int m,a,b,c;
        cin>>m>>a>>b>>c;
        int ans=0,rem=0;
        ans+=min(m,a);
        rem+=m-min(m,a);
        ans+=min(m,b);
        rem+=m-min(m,b);
        ans+=min(rem,c);
        cout<<ans<<'\n';
    }
}