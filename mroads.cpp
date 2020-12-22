//https://vn.spoj.com/problems/MROADS/

#include <bits/stdc++.h>
using namespace std;

#define lint long long
#define pii pair<int, int> 
#define ld long double
#define TASK "mroads"

const int N = 100001;

struct TForwardEdge 
{
    int v, a, b;
};

vector<TForwardEdge> g[N];

int n, k;

void enter() 
{
    cin >> n >> k;
    for (int i=1, u, v, a, b; i<n; ++i) 
    {
        cin >> u >> v >> a >> b;
        g[u].push_back({v, a, b});
        g[v].push_back({u, a, b});
    }
}

int f[N];
bool donef[N];

int F (int u, int par = -1) 
{
    if (donef[u])
        return f[u];
    for (auto v : g[u]) 
    {
        if (v.v == par) continue;
        f[u] = max(f[u], F(v.v, u) + v.a);
    }
    donef[u] = true;
    return f[u];
}

const int oo = 1e9 + 10;

int Cost(int maxD, int u = 1, int par = -1) 
{
    if (f[u] == 0 && maxD > 0)
        return oo;
    int ret = 0;
    for (auto v : g[u]) 
    {
        if (par == v.v) continue;
        if (v.a + f[v.v] > maxD) 
        {
            if (v.b + f[v.v] <= maxD) 
            {
                ret += v.a + f[v.v] - maxD;
            }
            else 
            {
                ret += v.a - v.b;
                ret += Cost(maxD - v.b, v.v, u);
                if (ret >= oo) 
                    return oo;
            }
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    enter();
    F(1);
    int lo = 0, hi = 1e9, md, ans;
    while (lo <= hi)
    {
        md = (lo + hi)  / 2;
        if (Cost(md) <= k) 
        {
            hi = md - 1;
            ans = md;
        }
        else 
        {
            lo = md + 1;
        }
    }
    cout << ans;
}
