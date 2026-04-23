#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<char>s(n,'a');
    for(int i=n-2;i>=0;i--){
        int cnt = n-i-1;
        if(k>cnt) k-=cnt;
        else{
            s[i]='b';
            s[n-k]='b';
            break;
        }
    }

    for(auto c:s) cout<<c;
    cout<<endl;
}

signed main(){
    int t; cin>>t;
    while(t--) solve();
}