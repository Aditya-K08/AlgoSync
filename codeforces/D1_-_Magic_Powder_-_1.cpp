#include<bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)

int main(){
    fastio();

    int n,k;
    cin>>n>>k;

    vector<int>a(n),b(n);
    for(int &x:a)cin>>x;
    for(int &x:b)cin>>x;

    auto can=[&](long long x){
        long long need=0;
        for(int i=0;i<n;i++){
            long long req=1LL*a[i]*x;
            if(req>b[i]) need+=req-b[i];
            if(need>k) return false;
        }
        return need<=k;
    };

    long long l=0,r=1e9,ans=0;

    while(l<=r){
        long long mid=(l+r)/2;
        if(can(mid)){
            ans=mid;
            l=mid+1;
        }else r=mid-1;
    }

    cout<<ans<<"\n";
}