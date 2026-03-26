// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<char>>arr(n,vector<char>(n));
    for(auto &x:arr){
        for(auto &y:x) cin>>y;
    }
    for(int i=0;i<n;i+=k){
        for(int j=0;j<n;j+=k){
            cout<<arr[i][j];
        }
        cout << "\n";
    }
}
int main() {
	int t;
    cin>>t;
    while(t--) solve();
    return 0;
}