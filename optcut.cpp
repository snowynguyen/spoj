#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int> 
#define lint long long
#define ld long double
#define TASK "OPTCUT"

const int N = 2002, oo = 1000000007;
int n, a[N];

void enter() 
{
    cin >> n;
    for (int i=1; i<=n; ++i) 
        cin >> a[i];
}

lint f[N][N];
int p[N];

int G(int l, int r) 
{
    if (l == r) return 0;
    if (l == r-1) return a[l] + a[r];
    if (f[l][r] != -1) return f[l][r];
    f[l][r] = oo;
    for (int k=l; k<r ; ++k) 
    {
        f[l][r] = min(f[l][r], G(l, k) + G(k+1, r));
    }
    f[l][r] +=  p[r] - p[l-1];
    return f[l][r];
}

int solve() 
{
    for (int l=1; l<=n; ++l)
    for (int r=1; r<=n; ++r) 
        f[l][r] = -1;
    for (int i=1; i<=n; ++i) p[i] = p[i-1] + a[i];
    return G(1, n);
}

void driver()
{
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    enter();
    cout << solve();
}

int main()
{
    ios_base::sync_with_stdio(false);
    driver();
}
