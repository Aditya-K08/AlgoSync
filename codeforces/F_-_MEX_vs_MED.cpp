#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int>pos;

int cnt(int l,int r,int k){
    int len=r-l+1;
    int s=k-len;
    if(s<0) return 0;
    int u=n-1-r;
    int a=min(l,u), b=max(l,u);

    if(s<a){
        return (s+1)*(s+2)/2;
    }
    if(s<b){
        return (a+1)*(s+1)-a*(a+1)/2;
    }
    if(s<a+b){
        return (a+1)*(b+1)-(a+b-s)*(a+b-s+1)/2;
    }
    return (a+1)*(b+1);
}

void solve(){
    cin>>n;
    vector<int>p(n);
    pos.assign(n,0);
    for(int i=0;i<n;i++){
        cin>>p[i];
        pos[p[i]]=i;
    }

    int ans=0;
    int L=pos[0],R=pos[0];

    for(int m=1;m<n;m++){
        int l1=L,r1=R;
        int l2=min(L,pos[m]);
        int r2=max(R,pos[m]);
        ans+=cnt(l1,r1,2*m)-cnt(l2,r2,2*m);
        L=l2;
        R=r2;
    }

    ans+=cnt(L,R,2*n);
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}