#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto &x:a) cin>>x;
    int pos=n-1;
    int phase=0;

    while(pos>0){
        if(phase==0){
            if(a[pos-1]>=a[pos]) pos--;
            else phase=1;
        }else{
            if(a[pos-1]<=a[pos]) pos--;
            else break;
        }
    }
    cout<<pos<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}