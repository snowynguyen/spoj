#include <bits/stdc++.h>
using namespace std;
const int M = 20;
const int N = 1 << M;
int c[N], n, f[N];

int main(int argc, char** argv)
{
    freopen("evencomb.inp", "r", stdin);
    freopen("evencomb.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int x, i=0; i<n; i++) {
        cin >> x;
        c[x]++;
        f[x]++;
    }
    for (int b = 0; b < M; ++b) {
        for (int mask = 0; mask < N; mask++) { 
            if (mask & (1 << b) ) {
                f[mask] += f[mask ^ (1 << b)];
            }
        }
    }
    long long ans = (long long) n * (n - 1) / 2;
    for (int mask = 0; mask < N; mask++) { 
        ans = ans - ((long long)(f[mask] - c[mask]) * (c[mask]));
        ans = ans - ((long long)c[mask] * (c[mask] - 1) / 2);
        //cerr << f[mask] << " ";
    }
    cout << ans << endl;
}