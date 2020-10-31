#warning not accepted

/** 
 * 
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
int nGirls,nBoys;

int boyAssignedtoGirl[N];
int visited[N];
vector<int> g[N];
int ttime = 0;

int DFS(int u) 
{
    if (visited[u] == ttime) 
        return false;
    visited[u] = ttime; 

    for (int v : g[u]) 
    {
        if (!boyAssignedtoGirl[v]) 
        {
            boyAssignedtoGirl[v] = u;
            return true;
        }
    }

    for (int v : g[u]) 
    {
        if (boyAssignedtoGirl[v]) 
        {
            if (DFS(boyAssignedtoGirl[v])) 
            {
                boyAssignedtoGirl[v] = u;
                return true;
            }
        }
    }

    return false;
}

int main() 
{
    cin >> nGirls >> nBoys;
    for (int i=1,u,v; i<=nBoys; ++i) 
    {
        cin >> u >> v;
        g[i].push_back(u);
        g[i].push_back(v);
    }
    int answer = 0;
    for (int i=1; i<=nBoys; ++i) 
    {
        ++ttime;
        answer += DFS(i);
    }
    cout << answer;
}