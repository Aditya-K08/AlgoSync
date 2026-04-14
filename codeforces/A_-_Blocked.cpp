// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>freq(101,0);
    vector<int>arr(n);
    for(auto &x:arr){
        cin>>x;
        freq[x]++;
    }
    for(int i=0;i<101;i++){
        if(freq[i]>1){
            cout<<-1<<endl;
            return;
        }
    }
    sort(arr.begin(),arr.end(),greater<int>());
    for(auto &x:arr) cout<<x<<" ";
    cout<<"\n";
}

int main() {
	int t;
    cin>>t;
    while(t--) solve();
    return 0;
}