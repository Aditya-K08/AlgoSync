#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    stack<char>st;
    int cnt=0;
    int i=0;
    while(i<n){
        if(s[i]==')' && !st.empty()){
            cnt+=2;
            st.pop();
        }else {
            st.push(')');
        }
        i++;
    }
    cout<<cnt<<" ";
}

int main(){
    solve();
    return 0;
}