#include <bits/stdc++.h>
using namespace std;
#define lint long long
const int N = 1000002;
const lint ooo = 1e17;

struct TVertex { 
    int u, color;
    lint w;

    bool operator < (const TVertex &h) const {
        return w > h.w;
    }
} f[N][2];

bool visited[N][2];

struct TEdge {
    int v, w;
};

vector<TEdge> g[N];
int color[N];
int s, t, n, m;


int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int u, v, w; cin >>u >> v >> w;
        g[u].push_back({v, w});
    }
    {
        int k ; cin >> k;
        for (int i=1;i<=k; ++i) {
            int u; cin >> u; 
            color[u] = 1;
        }
    }
    for (int i=1; i<=n; ++i) {
        f[i][0].w = f[i][1].w = ooo;
    }
    f[s][color[s]].w = 0;
    f[s][color[s]].u = s;
    f[s][color[s]].color = color[s];
    priority_queue<TVertex> heap;
    heap.emplace(f[s][color[s]]);
    while (!heap.empty()) {
        auto u = heap.top(); heap.pop();
        if (visited[u.u][u.color]) continue;
        visited[u.u][u.color] = true;
        for (auto v : g[u.u]) {
            
        }
    }
}