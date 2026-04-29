#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
		cin >> s;
		reverse(s.begin(), s.end());
		for (char &c : s) {
            if (c == 'q') c = 'p';
            else if (c == 'p') c = 'q';
        }
		cout << s << '\n';
    }
}