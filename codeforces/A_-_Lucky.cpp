#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int sum=s[0]+s[1]+s[2]-3*'0';
    sum-=s[4]+s[5]+s[3]-3*'0';
    if(sum==0){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}