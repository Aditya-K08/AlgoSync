#include <bits/stdc++.h>
using namespace std;
 
static const int MOD = 1000000007;
 
int main() {
    int r,g;
    cin>>r>>g;
 
    int h=0;
    while((h+1)*(h+2)/2<=r+g) h++;
 
    vector<int> dp(r+1,0);
    dp[0]=1;
 
    for(int i=1;i<=h;i++){
        for(int j=r;j>=i;j--){
            dp[j]=(dp[j]+dp[j-i])%MOD;
        }
    }
  
  
    int total=h*(h+1)/2;
    int ans=0;
 
    for(int j=0;j<=r;j++){
        int green_used=total-j;
        if(green_used<=g){
            ans=(ans+dp[j])%MOD;
        }
    }
 
    cout<<ans<<"\n";
    return 0;
}