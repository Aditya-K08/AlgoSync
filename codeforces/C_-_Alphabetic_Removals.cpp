#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    vector<int>freq(26,0);
    for(char c:s) freq[c-'a']++;

    vector<int>remove(26,0);

    for(int i=0;i<26;i++){
        int take=min(freq[i],k);
        remove[i]=take;
        k-=take;
    }
    string ans="";
    for(char c:s){
        if(remove[c-'a']>0){
            remove[c-'a']--;
        }else{
            ans+=c;
        }
    }

    cout<<ans<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}