#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<string>arr(n);
    for(auto &x:arr) cin>>x;
    vector<int>cnt(1<<24,0);
    for(string s:arr){
        int mask = (1<<(s[0]-'a')) | (1<<(s[1]-'a')) | (1<<(s[2]-'a'));
        cnt[mask]++;
    }
    vector<int>dp=cnt;
    for(int b=0; b<23; b++){
        for(int mask=0; mask<(1<<22); mask++){
            if(mask&(1<<b))
                dp[mask]+=dp[mask^(1<<b)];
        }
    }
    long long ans=0;
    for(string s:arr){
        int mask2=(1<<(s[0]-'a')) | (1<<(s[1]-'a')) | (1<<(s[2]-'a'));
        for(int mask=0;mask<(1<<22);mask++){
            //correct = n - sos[((1<<24)-1) ^ v]
            int cor = n-dp[((1<<22)-1)^mask2];
            ans^=cor*cor;
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}