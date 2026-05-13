#include<bits/stdc++.h>
using namespace std;
#define int long long

int calc(int k,int a,int x,int b,int y){
    int ans=0;
    if(k>=a){
        int cnt=(k-a)/x + 1;
        ans+=cnt;
        k-=cnt*x;
    }
    if(k>=b){
        int cnt=(k-b)/y + 1;
        ans+=cnt;
    }
    return ans;
}

void solve(){
    int k,a,b,x,y;
    cin>>k>>a>>b>>x>>y;
    cout<<max(calc(k,a,x,b,y),calc(k,b,y,a,x))<<"\n";
}

signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}