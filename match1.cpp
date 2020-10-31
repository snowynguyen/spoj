#include <bits/stdc++.h>
using namespace std;

int m,n;
const int N = 101;
vector<int> g[N];

int visited[N], assigned[N];
int ttime = 0;

bool dfs(int u) 
{
    if (visited[u] == ttime) 
        return false;
    else 
        visited[u] = ttime;
    
    for (int v : g[u]) 
    {
        if (!assigned[v]) 
        {
            assigned[v] = u;
            return true;
        }
    }
    
    for (int v : g[u]) 
    {
        if (assigned[v]) 
        {
            if (dfs(assigned[v])) 
            {
                assigned[v] = u;
                return true;
            }
        }
    }

    return false;
}

int main() 
{
    freopen ("match1.inp", "r", stdin);
    cin >> m >> n;
    int u, v;
    while (cin  >> u >> v) 
        g[u].push_back(v);

    int answer = 0;

    for (int i=1; i<=m; ++i) 
    {
        ttime++;
        answer += dfs(i);
    }
    cout << answer << endl;
    for (int i=1; i<=n; ++i) 
    {
        if (assigned[i]) 
        {
            cout << assigned[i] << " " << i << endl;
        }
    }
}