#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    unordered_map<int,int>next;
    unordered_map<int,int>prev;

    int start=0;

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        next[a]=b;
        prev[b]=a;
        if(a==0) start=b;
    }

    vector<int>ans(n);
    ans[0]=start;

    if(n>1) ans[1]=next[start];

    for(int i=2;i<n;i++){
        ans[i]=next[ans[i-2]];
    }

    for(int x:ans) cout<<x<<" ";
}

int main(){
    solve();
}