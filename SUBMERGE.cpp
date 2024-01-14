#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
vector<int> g[N];
int n, m;


void enter()
{

    for (int  u, v,i=1; i<=m; ++i)
    {
        cin >>u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

int num[N], low[N], vt;

void dfs(int u)
{
    num[u] = low[u]
    for (int v : g[u])
    {

    }
}

int solve()
{

}

int main()
{
    while (cin >> n >> m)
    {
        for (int i=1; i<=n; ++i)
        {
            g[i].clear();
        }
        enter();
        cout << solve();
    }
}
