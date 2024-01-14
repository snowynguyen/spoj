#include <bits/stdc++.h>
using namespace std;
#define lint long long
#define pii pair<int, int> 
#define ld long double
#define TASK ""

int n,k,t;
lint base;
vector<int> A;

lint multi(lint a, lint b, lint mod) 
{
    if (b == 0)
        return 0;
    if (b == 1) 
        return a;
    lint c = multi(a, b / 2, mod);
    c += c;
    if (b % 2 == 1) 
        c += a;
    return c % mod;
}

lint pw (lint a, lint b, lint mod)
{
    if (b == 0) 
        return 1;
    lint c = pw(a, b/2, mod);
    c = multi(c, c, mod);
    if (b % 2 == 1) 
        c = multi(c, a, mod);
    return c;
}

void enter() 
{
    cin >> n >> k >> t >> base;
    lint m, s; cin >> m >> s;
    A.resize(n);
    A[0] = (m * s + s) % (1LL << 30LL);
    for (int i=1; i<n; ++i) 
    {
        A[i] = (A[i - 1] * m + s) % (1LL << 30LL);
    }
}

vector<pair<lint, int > > B;

void Factorize_Base() 
{
    lint b =  base;
    for (int d = 2; d <= 1000000; ++d) 
    {
        if  (b % d == 0) 
        {
            int f = 0;
            while (b % d == 0) 
            {
                b /= d;
                ++f;
            }
            B.push_back({d, f});
        }
    }
    if (b > 1) 
        B.push_back({b, 1});
}

long long res = 0;

lint euler (pair<lint, int > n) 
{
    lint r = n.first - 1;
    for (int i=1; i<n.second; ++i) 
        r = r * n.first;
    return r;
}

lint eval (pair<lint, int> a) 
{
    lint x = 1;
    while (a.second--)
        x *= a.first;
    return x;
}

unordered_map<lint, lint> kt_on_mod;

lint KT_on_mod(lint mod) 
{
    if (kt_on_mod.count(mod))
        return kt_on_mod[mod];
    kt_on_mod[mod] = pw(k, t, mod);
    return kt_on_mod[mod];
}

const lint OO = 1e18;
lint KT;

void solve() 
{
    KT = 1;
    for (int i=1; i<=t; ++i) 
    {
        KT *= k;
        if (KT > 1e12) 
        {
            KT = OO;
            break;
        }
    }

    lint rem, det, cr ,cd, g, eb;
    for (int &a : A) 
    {
        if (a == 0) 
            continue;
        if (a == 1) 
        {
            res = (res + 1) % base;
            continue;
        }
        rem = 0;
        det = 1;    
        bool flag;
        lint t1, t2;
        for (auto &b : B) 
        {
            eb = eval(b);
            g = __gcd((lint)a, eb);
            if (g == 1) 
            {
                cr = KT_on_mod(euler(b));
                cr = pw(a, cr, eb);
            }
            else 
            {
                if (KT >= b.second) 
                    continue;
                flag = false;
                t1 = 1;
                t2 = KT;
                while (t2--)
                {
                    t1 *= g;
                    if (t1 >= eb) 
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag) 
                    continue;
                  
            }
        }
    }
}

void driver()
{
     enter();
     Factorize_Base();
     solve();
     cout << res;
}  

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    driver();
}
cout << Cal(x , u;)