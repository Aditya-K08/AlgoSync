// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,q;
    cin>>n>>q;
    string a,b;
    cin>>a>>b;
    vector<vector<int>> prefA(n+1,vector<int>(26,0));
    vector<vector<int>> prefB(n+1,vector<int>(26,0));
    for(int i=0;i<n;i++){
        prefA[i+1]=prefA[i];
        prefB[i+1]=prefB[i];
        prefA[i+1][a[i]-'a']++;
        prefB[i+1][b[i]-'a']++;
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int ans=0;
        for(int c=0;c<26;c++){
            int cntA = prefA[r][c]-prefA[l-1][c];
            int cntB = prefB[r][c]-prefB[l-1][c];
            if(cntA>cntB) ans += (cntA-cntB);
        }
        cout<<ans<<"\n";
    }
}
int main() {
	int t;
    cin>>t;
    while(t--) solve();
    return 0;
}