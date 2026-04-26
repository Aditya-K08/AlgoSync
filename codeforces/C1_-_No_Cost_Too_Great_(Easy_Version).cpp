#include <bits/stdc++.h>
using namespace std;

const int MAXA = 200005;

vector<int> spf(MAXA + 1);

void buildSPF() {
    for (int i = 0; i <= MAXA; i++) spf[i] = i;

    for (int i = 2; i * i <= MAXA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

vector<int> getPrimeFactors(int x) {
    vector<int> primes;

    while (x > 1) {
        int p = spf[x];
        primes.push_back(p);

        while (x % p == 0) {
            x /= p;
        }
    }

    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    buildSPF();

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<int> freq(MAXA + 1, 0);

        bool zero = false;

        for (int i = 0; i < n; i++) {
            vector<int> primes = getPrimeFactors(a[i]);

            for (int p : primes) {
                if (freq[p] > 0) {
                    zero = true;
                }
                freq[p]++;
            }
        }

        if (zero) {
            cout << 0 << '\n';
            continue;
        }

        bool one = false;

        for (int i = 0; i < n; i++) {
            vector<int> primes = getPrimeFactors(a[i] + 1);

            for (int p : primes) {
                if (freq[p] > 0) {
                    one = true;
                    break;
                }
            }

            if (one) break;
        }

        if (one) cout << 1 << '\n';
        else cout << 2 << '\n';
    }

    return 0;
}