// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

void solve(){
    string s;
    cin>>s;
    unordered_set<char>st;
    for(char c:s) st.insert(c);
    if(st.size()==1){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]){
                swap(s[i],s[i-1]);
            }
        }
        cout<<s<<"\n";
    }
}

int main() {
	int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}