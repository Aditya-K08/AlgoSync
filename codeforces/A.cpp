#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int cnt=count(arr.begin(),arr.end(),1);
    if(cnt>0){
        cout<<"HARD"<<endl;
    }else{
        cout<<"EASY"<<endl;
    }
}

int main(){
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}