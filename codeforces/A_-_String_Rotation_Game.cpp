#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
    Author : Zenith
*/
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=1;
    bool flag=false;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]) cnt++;
        else flag=true;
    }
    if(flag){
        if(s[0]!=s[n-1]) cout<<cnt+1<<endl;
        else cout<<cnt<<endl;
    }else{
        cout<<cnt<<endl;
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