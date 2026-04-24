#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(s[i]==t[i]) continue;
        if(s[i]>t[i]) cnt1++;
        if(s[i]<t[i]) cnt2++;
    }
    if(cnt1==cnt2){
        cout<<"EQUAL\n";
    }else if(cnt1>cnt2){
        cout<<"RED\n";
    }else{
        cout<<"BLUE\n";
    }
}

int32_t main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}