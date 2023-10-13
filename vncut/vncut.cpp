#include <bits/stdc++.h>
using namespace std;

const int N = 5001, oo = 1e7;

int f[N][N];

int F(int n, int m) {
    if (f[n][m]) 
        return f[n][m];
    int &res = f[n][m];
    if (n > m) {
        res = F(m, n);
    } else if (n == 1) {
        res = m; 
    } else if (n == 2) {
        res = (m >> 1) + ((m & 1) << 1);
    } else if (m % n == 0) { 
        res = m / n;
    } else {
        int i, j;
        res = oo;
        for (i=1; i+i <= n; ++i) {
            j = F(i, m);
            if (j < res) {
                j += F(n - i, m);
                if (j < res) {
                    res = j;
                }
            }
        }
        for (i=1; i+i <= m; ++i) {
            j = F(n, i);
            if (j < res) {
                j += F(n, m - i);
                if (j < res) {
                    res = j;
                }
            }
        }
    }
    return res;
}

int F2(int n, int m) {
    if (f[n][m]) 
        return f[n][m];
    int &res = f[n][m];
    if (n > m) {
        res = F2(m, n);
    } else if (n == 1) {
        res = m; 
    } else if (n == 2) {
        res = (m >> 1) + ((m & 1) << 1);
    } else {
        int g = __gcd(n, m);
        if (g > 1) 
            res = F(n / g, m / g);
        else {
            if (m / n >= 2) {
                res = m / n - 2 + F(n, m - (m / n - 2) * n);
            } else {
                int i, j;
                res = oo;
                for (i=1; i+i <= m; ++i) {
                    j = F2(n, i);
                    if (j < res) {
                        j += F2(n, m - i);
                        if (j < res) {
                            res = j;
                        }
                    }
                }
                for (i=1; i+i <= n; ++i) {
                    j = F2(i, m);
                    if (j < res) {
                        j += F2(n - i, m);
                        if (j < res) {
                            res = j;
                        }
                    }
                }
            }
        }
    }
    return res;
}

int G(int n, int m) {
    if (m % n == 0) {
        return m / n;
    }   
    return m / n + G(m % n, n);
}

void driver() {
    int n, m; cin >> n >> m;    
    cout << F2(n, m);
}

void test() {
    for (int i=1; i<30; ++i) {
        for (int j=1; j<61; ++j) {
            if (F(i, j) != G(i, j)) {
                printf("i=%3d, j=%3d, f=%3d, g=%3d\n", i, j, F(i, j), G(i, j));
            }
        }
    }
}

int main() {
    test();
}