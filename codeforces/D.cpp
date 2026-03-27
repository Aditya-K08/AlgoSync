#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
    Author : Zenith
*/
int sum(int n){
    int s=0;
    while(n>0){
        s+=n%10;
        n/=10;
    }
    return s;
}
void solve(){
    int n,m;
    cin>>n>>m;
    if(sum(n)<=m){
        cout<<0<<endl;
        return;
    }
    int cnt=0;
    int mul=1;
    for(int i=0;i<18;i++){
        int rem=(n/mul)%10;
        int toadd=mul*((10-rem));
        n+=toadd;
        cnt+=toadd;
        if(sum(n)<=m){
            break;
        }
        mul*=10;
    }
    cout<<cnt<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}