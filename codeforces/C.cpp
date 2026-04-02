#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    stack<char>st;
    for(int i=0;i<n;i++){
        if(s[i]=='(') st.push('(');
        else{
            if(st.empty()) cnt++;
            else st.pop();
        }
    }
    cout<<cnt<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}