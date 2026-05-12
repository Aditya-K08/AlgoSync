#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    if(a==b){
        cout<<0<<"\n";
        return;
    }
    if(a>b){
        if((a^1)==b){
            cout<<y<<"\n";
        }else{
            cout<<-1<<"\n";
        }
        return;
    }
    int cnt=0;
    while(a<b){
        if(a&1){
            cnt+=x;
        }else{
            cnt+=min(x,y);
        }
        a++;
    }
    cout<<cnt<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--) solve();

    return 0;
}