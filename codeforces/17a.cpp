#include<bits/stdc++.h>
using namespace std;
#define int long long

int maxi=1001;
vector<bool>is_primes(maxi,true);
vector<int>primes;

void seive(){
    is_primes[0]=is_primes[1]=false;
    for(int i=2;i*i<maxi;i++){
        if(is_primes[i]){
            for(int j=i*i;j<maxi;j+=i){
                is_primes[j]=false;
            }
        }
    }
    for(int i=2;i<maxi;i++){
        if(is_primes[i]) primes.push_back(i);
    }
}

void solve(){
    int n,k;
    cin>>n>>k;
    int cnt=0;
    for(int i=1;i<primes.size();i++){
        int x=primes[i-1]+primes[i]+1;
        if(x<=n && x<maxi && is_primes[x]) cnt++;
        if(cnt>=k){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int32_t main(){
    seive();   
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}