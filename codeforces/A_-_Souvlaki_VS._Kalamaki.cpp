    for (auto& x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    bool ok = true;
    for (int j = 1; j < n - 1; j += 2) {
        if (a[j] != a[j + 1]) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout << "YES"<< '\n';
    
    
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}