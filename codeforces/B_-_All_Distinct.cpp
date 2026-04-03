#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    set<int>st(arr.begin(),arr.end());
    int sz=st.size();
    int rem=n-sz;
    if(rem&1){
        cout<<sz-1<<endl;
    }else{
        cout<<sz<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}