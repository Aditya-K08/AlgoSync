#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(2*n);
    for(auto &x:arr) cin>>x;
    set<int>st;
    vector<int>res;
    for(int x:arr){
        if(!st.count(x)) res.push_back(x);
        st.insert(x);
    }
    for(auto x:res) cout<<x<<" ";
    cout<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}