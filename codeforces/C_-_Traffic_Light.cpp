#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    char x;
    cin>>n>>x;
    string s;
    cin>>s;
    vector<int>pos1,pos2;
    for(int i=0;i<n;i++){
        char c=s[i];
        if(c==x){
            pos1.push_back(i);
        }else if(c=='g'){
            pos2.push_back(i);
        }
    }
    if(pos2.empty()){
        cout<<0<<"\n";
        return;
    }
    int sz1=pos1.size(),sz2=pos2.size();
    int l=0,r=0;
    int ans=0;
    for(int i=0;i<pos1.size();i++){
        int idx = pos1[i];
        auto it = lower_bound(pos2.begin(), pos2.end(), idx);
        if(it != pos2.end()){
            ans = max(ans, *it - idx);
        } else {
            ans = max(ans, n - idx + pos2[0]);
        }
    }
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