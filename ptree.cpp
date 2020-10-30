#warning not accepted
/** WA. 
 *  NOT SOLVED YET!  
 *  TODO: check out https://github.com/leduythuccs/VOJ-rebuild-discord-bot/blob/master/statement_resources/ptree.rar for solution
*/

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int> 
#define lint long long
#define ld long double
#define TASK "ptree"

const int N = 201;
int n, p, a[N];
vector<int> g[N];

int f[N][N];
int cnt[N];
const int oo = 1e7;

bool maxi(int &a, int b) 
{
    if (b > a) 
    {
        a = b; return true;
    }
    return false;
}

pii trace[N][N];

void F(int u, int par) 
{
    int tz = 1;
    f[u][1] = a[u];
    int i,j,k=-1;
    for (int v : g[u]) 
    {
        ++k;
        if (v == par) continue;
        F(v, u);
        for (i=tz; i>=1; --i) 
        {
            for (j=cnt[v]; j>=0; --j) 
            {
                if (maxi(f[u][i+j], f[u][i] + f[v][j]))
                {
                    trace[u][i+j]={k, j};
                }
            }
        }
        tz += cnt[v];
    }
}

void T(int u, int par, int x) 
{
    cout <<u << " ";
    if (x > 1) 
    {
        int j = trace[u][x].first;
        while (j) 
        {
            T(g[u][trace[u][x].first], u, trace[u][x].second);
            x -= trace[u][x].second;
            j = trace[u][x].first;
        }
    }
}

void dfs(int u, int par) 
{
    cnt[u] = 1;
    for (int v : g[u]) 
    {
        if (v == par) continue;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
}

void enter() 
{
    cin >> n >> p;
    for (int i=1; i<=n; ++i) 
    {
        cin >> a[i];
    }
    for (int i=1,u,v; i<n; ++i )
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void solve() 
{
    for (int i=1; i<=n; ++i) 
    {
        for (int j=1; j<=n; ++j) 
        {
            f[i][j] = -oo;
        }
    }
    dfs(1, 0);
    F(1,0);
    int ma = 1;
    for (int i=1;i<=n; ++i) 
    {
        if (f[i][p] > f[ma][p]) 
        {
            ma = i;
        }
    }
    T(ma, 0, p);
}

void driver()
{
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    enter();
    solve();
}

int main()
{
    ios_base::sync_with_stdio(false);
    driver();
}
