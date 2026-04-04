#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=1;i<=k;i++){
        for(int j=1;j<n;j++){
            if(s[j-1]=='B' && s[j]=='G'){
                s[j]='B';
                s[j-1]='G';
                j++;
            }
        }
    }
    cout<<s<<endl;
    return 0;
}