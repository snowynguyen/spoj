#include "bits/stdc++.h" 
using namespace std;

const int N = 202;
int m, n;
char a[N][N];

void input() {
    scanf("%d%d", &m, &n);
    for (int i=1; i<=m; ++i) {
        scanf("%s", a[i]+1);
    }
}

struct Node {
    int x, y, dir;
};




int main() {
    input();
}