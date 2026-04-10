#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    int fours=count(s.begin(),s.end(),'4');
    int sevens=count(s.begin(),s.end(),'7');
    if(fours+sevens==n){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main(){
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}