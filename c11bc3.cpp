#include <bits/stdc++.h>

using namespace std;

int m, n, p;
const int N = 102;

int green[N][N], red[N][N], pg[N][N], pr[N][N];

int getred(int ilo, int jlo, int ihi, int jhi) {
    if (ilo > ihi) return 0; 
    if (jlo > jhi) return 0;
    return pr[ihi][jhi] - pr[ihi][jlo-1] - pr[ilo-1][jhi] + pr[ilo-1][jlo-1];
}

int getgreen(int ilo, int jlo, int ihi, int jhi) {
    if (ilo > ihi) return 0; 
    if (jlo > jhi) return 0;
    return pg[ihi][jhi] - pg[ihi][jlo-1] - pg[ilo-1][jhi] + pg[ilo-1][jlo-1];
}

int res[N][N];


int main() {
    cin >> m >> n >> p;
    for (int i=1; i<=m; ++i) {
        string s; cin >> s; s = " " + s;
        for (int j=1; j<=n; ++j) {
            if (s[j] == '1') {
                green[i][j] = 1;
            }
            else if (s[j] == '2') {
                red[i][j] = 1;
            }
        }
    }
    for (int i=1; i<=m; ++i) {
        for (int j=1; j<=n; ++j) {
            pg[i][j] = pg[i-1][j] + pg[i][j-1] - pg[i-1][j-1] + green[i][j];
            pr[i][j] = pr[i-1][j] + pr[i][j-1] - pr[i-1][j-1] + red[i][j];
            res[i][j] = 1<<29;
        }
    }
    
    for (int x=1; x+p-1<=m; ++x) {
        for (int y=1; y+p-1<=n; ++y) {
            for (int u=1; u+p-1<=m; ++u) {
                for (int v=1; v+p-1<=n; ++v) {
                    int cur = pg[m][n];
                    cur -= getgreen(x, y, x+p-1, y+p-1);
                    cur += getred  (x, y, x+p-1, y+p-1);
                    cur -= getgreen(u, v, u+p-1, v+p-1);
                    cur += getred  (u, v, u+p-1, v+p-1);
                    cur += 2*getgreen(max(x, u), max(y, v), min(x, u)+p-1, min(y, v)+p-1);
                    cur -= 2*getred  (max(x, u), max(y, v), min(x, u)+p-1, min(y, v)+p-1);
                    res[x][y] = min(res[x][y], cur);
                }
            }
        }
    }
    
    for (int x=1; x+p-1<=m; ++x) {
        for (int y=1; y+p-1<=n; ++y) {
            cout << res[x][y] << " ";
        }
        cout << endl;
    }
    return 0;
}
