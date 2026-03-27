#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
    Author : Zenith
*/
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ones=count(s.begin(),s.end(),'1');
    if(n&1 &&  ones&1){
        cout<<-1<<endl;
        return;
    }
    int zeros=count(s.begin(),s.end(),'0');
    if(zeros&1){
        cout<<zeros<<endl;
        if(zeros!=0){ 
            for(int i=0;i<n;i++){
                if(s[i]=='0') cout<<i+1<<" ";
            }
            cout<<endl;
        }
    }else{
        cout<<ones<<endl;
        if(ones!=0){
            for(int i=0;i<n;i++){
                if(s[i]=='1') cout<<i+1<<" ";
            }
            cout<<endl; 
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}