// https://codeforces.com/group/FLVn1Sc504/contest/274485/problem/P

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int> 
#define lint long long
#define ld long double

lint f[32][2][2][17];
bool done[32][2][2][17];
int n;

int a[32];
lint K;

void enter()
{
    cin >> n;
    for (int i=0; i<= n+ n; ++i) 
        cin >> a[i];
    cin >> K;
}

lint F(int i, bool isLess, int v) 
{
    if (v < 0)
        return 0;
    if (i == n + n) 
        return v == 0;
    if (done [i][isLess][1][v])
        return f[i][isLess][1][v];

    lint &ans = f[i][isLess][1][v];
    
    if (isLess) 
    {
        ans = F(i + 1, true, v + 1) + F(i + 1, true, v - 1);
    }
    else 
    {
        if (v + 1 < a[i+1]) 
        {
            ans = F(i + 1, true, v + 1);
            ans += F(i + 1, true, v - 1);
        }
        else if (v + 1 == a[i+1]) 
        {
            ans = F(i + 1, false, v + 1);
            ans += F(i + 1, true, v - 1);
        }
        else if (v == a[i+1]) 
        {
            ans = F(i + 1, true, v - 1);
        }
        else if (v - 1 == a[i+1]) 
        {
            ans = F(i + 1, false, v - 1);
        }
    }
    done[i][isLess][1][v] = true;
    return ans;
}

void solve() 
{
    cout << F(0, 0, 0) << endl;

    cout<< 0 ;
    lint nt;
    int v = 0;
    for (int i=1; i<=n+n; ++i) 
    {
        for (int j = i; j<=n+n; ++j)
        {
            a[j] = min(a[i-1] + j - i + 1, n + n - j);
        }
        memset(done, 0, sizeof(done));
        nt = F(i, false, v - 1);
        if (nt < K) 
        {
            K -= nt;
            v = v + 1;
        }
        else 
        {
            v = v - 1;
        }
        cout << ' ' << v;
        a[i] = v;
        flush(cout);
    }
}

void driver()
{
    enter();
    solve();
}

int main()
{
    ios_base::sync_with_stdio(false);
    driver();
}
