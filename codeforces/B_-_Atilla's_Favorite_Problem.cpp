#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    char mx;
    for(char c:s){
        mx=max(c,mx);
    }
    string alpha="abcdefghijklmnopqrstuvwxyz";
    for(int i=0;i<26;i++){
        if(mx==alpha[i]) {
            cout<<i+1<<endl;
            return;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}