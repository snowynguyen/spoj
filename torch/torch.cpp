#include <bits/stdc++.h>

using namespace std;

const int N = 101;
int n;
#define pii pair<int, int> 
#define vi vector<int>
pii a[N];

void input() {
    cin >> n;
    for (int i=0; i<n; ++i) cin >> a[i].first >> a[i].second;
}

long long sqr(long long x) {
    return x * x;
}

double dist(pii u, pii v) {
    return sqrt(sqr(u.first - v.first) + sqr(u.second - v.second));
}

double cost(vi x) {
    double c = 0;
    for (int i=1; i<n; ++i) {
        c += dist(a[x[i-1]], a[x[i]]);
    }
    c += dist(a[x[n-1]], a[x[0]]);
    return c;
}

vector<int> opt2(vector<int> ini) {
    for (int iter = 0; iter <= 600; ++iter) {
        bool flag = true;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                auto p2 = ini; 
                swap(p2[i], p2[j]);
                double cost_ini = cost(ini);
                double cost_p2 = cost(p2);
                if (cost_p2 < cost_ini) {
                    ini = p2;
                    flag = false;
                }
            }
        }
        if (flag) break;
    }
    return ini;
}

mt19937 rd(123123123);

vi random_vi() {
    vi ret(n);
    for (int i=0; i<n; ++i) ret[i] = i;
    for (int i=1; i<n; ++i) {
        int j = rd()%(i + 1);
        swap(ret[i], ret[j]);
    }
    return ret;
}

vi solve() {
    vi best = {};
    double best_cost = 1e18;
    for (int i=0; i<(4200/n); ++i) {
        auto v = random_vi();
        v = opt2(v);
        if (cost(v) < best_cost) {
            best = v;
            best_cost = cost(v);
        }
    }
    return best;
}

void print(vi p) { 
    int d;
    for (int i=0; i<n; ++i) {
        if (p[i] == 0) {
            d = i;
            break;
        }
    }
    for (int i=d; i<n; ++i) cout << p[i] + 1 << " ";
    for (int i=0; i<d; ++i) cout << p[i] + 1 << " ";
    cout << endl;
}

vi nobrain() {
    return opt2(random_vi());
}

void driver() {
    input();
    auto ans = solve();
    cout << fixed << setprecision(9) << cost(ans) << endl;
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    driver();
    return 0;
}