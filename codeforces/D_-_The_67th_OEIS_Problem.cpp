#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int>primes;
vector<bool>is_prime(200005,true);
void seive(){
    is_prime[0]=is_prime[1]=false;
    for (int i=2;i*i<=200005;i++) {
        if (is_prime[i]){
            for (int j=i*i;j<=200005;j+=i)
                is_prime[j]=false;
        }
    }
    for(int i=0;i<=200005;i++){
        if(is_prime[i]) primes.push_back(i);
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    arr[0]=primes[0];
    for(int i=1;i<n-1;i++){
        arr[i]=primes[i-1]*primes[i];
    }
    arr[n-1]=primes[n-2];

    for(int x:arr) cout<<x<<" ";
    cout<<endl;
}

signed main(){
    int t;
    cin>>t;
    seive();
    while(t--) solve();
}