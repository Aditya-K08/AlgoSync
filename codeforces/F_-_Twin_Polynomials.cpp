            if(sz == 2){
                int u = nodes[0], v = nodes[1];
                if(a[u] == 0 || a[v] == 0) { bad = true; break; }
                if(a[u] == u || a[v] == v) { bad = true; break; }
                if(a[u] != -1 && a[u] != v){ bad = true; break; }
                if(a[v] != -1 && a[v] != u){ bad = true; break; }
                used[u] = used[v] = 1;
            } else {
                int x = nodes[0];
                if(a[x] == 0 || a[x] == x){
                    used[x] = 1;
                }
            }
        }
        if(bad){ cout<<0<<"\n"; continue; }
        int m = 0;
        for(int i=1;i<=n;i++) if(!used[i]) ++m;
        int ans = (!used[n]) ? Iinc[m] : S[m];
        cout << ans % MOD << "\n";
    }
    return 0;
}