// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>res;
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            char c;
            cin>>c;
            if(c=='#') res.push_back(j+1);
        }
    }
    reverse(res.begin(),res.end());
    for(int x:res) cout<<x<<" ";
    cout<<"\n";
}

int main() {
	int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}