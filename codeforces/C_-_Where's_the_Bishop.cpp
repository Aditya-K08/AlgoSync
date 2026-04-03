#include<bits/stdc++.h>
using namespace std;
void solve(){
    int x,y;
    vector<vector<char>>grid(8,vector<char>(8));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=1;i<7;i++){
        for(int j=1;j<7;j++){
            if(grid[i][j]=='#' && 
                grid[i-1][j-1]=='#' &&
                grid[i-1][j+1]=='#' &&
                grid[i+1][j-1]=='#' &&
                grid[i+1][j+1]=='#'
            ){
                cout<<i+1<<" "<<j+1<<endl;
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}