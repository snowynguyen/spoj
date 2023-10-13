#include "bits/stdc++.h"
using namespace std;

const int N = 100004;
int n, m, k;
int a[N], c[N];
bool b[N];


int main() {
    cin >>  n >> m >> k;
    int d = 0, dmin = 0, dmax = 0;
    for (int i=0; i<m; i++) { 
        cin >> a[i];
        if (a[i] == 1) {
            // go left 
            d -= 1;
        }
        else {
            d += 1;
        }
        dmin = min(d, dmin);
        dmax = max(d, dmax);
    }

    for (int i=1; i<=k; ++i) {
        cin >> c[i];
    }
    c[0] = 0;
    c[k + 1] = n + 1;

    int len = dmax - dmin + 1;
    int ret = 0;
    for (int i=0; i<=k; ++i) {
        int range = c[i + 1] - c[i] - 1;
        ret += max(0, range - len + 1);
    }
    cout << ret << endl;
}
