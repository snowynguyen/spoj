#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    int ans = 1e9, lt = 0, rt = 1e9, md;
    while (lt <= rt) {
        md = (lt + rt) / 2;
        bool ok = true; 

        int bus = 0;
        int fi = 0, la;
        while (fi < n) {
            la = upper_bound(a.begin(), a.end(), a[fi] + md) - a.begin();
            la = min (la, fi + c);
            bus++;
            fi = la;
        }

        ok = bus <= m;

        if (ok) {
            ans = md;
            rt = md - 1;
        }
        else {
            lt = md + 1;
        }
    }
    cout << ans << endl;
}