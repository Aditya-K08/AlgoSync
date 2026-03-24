    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        ull n;
        cin >> n;
        bool possible = false;
        for (int k = 1; k <= 60 && !possible; ++k) {
            if ((n >> k) != 0) continue;
            bool pal = true;
            for (int i = 0; i < k; ++i) {
                int ai = (int)((n >> i) & 1ULL);
                int aj = (int)((n >> (k - 1 - i)) & 1ULL);
                if (ai != aj) { pal = false; break; }
            }
            if (!pal) continue;
            if ((k & 1) && (((n >> (k / 2)) & 1ULL) == 1)) continue;
            possible = true;
        }
        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}