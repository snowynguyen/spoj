#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 9, oo = 1e7, G = 3;
#define pii pair<int, int>

struct TGrid{
    int a[N][N];

    TGrid() {
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                a[i][j] = (i * G + i / G + j) % N + 1;
            }
        }
    }

    int score(int x) {
        vector<pii> c;
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                if (a[i][j] == x)  
                    c.push_back({i, j});              
            }
        }
        if (c.size() == N) {
            int r = 0;
            for (int i=0; i<N; ++i) {
                for (int j=i+1; j<N; ++j) {
                    r += abs(c[j].first - c[i].first) * abs(c[j].second - c[i].second);
                }
            }
            return r;
        }
        else {
            return -oo;
        }
    }

    int score() {
        int r = 0;
        for (int i=1; i<=N; ++i) {
            r += score(i) * i;
        }
        return r;
    }

    vector<int> find_best_permute() { 
        vector< pii > si;
        for (int i=1; i<=N; ++i) {
            si.push_back({score(i), i});
        }
        sort(si.begin(), si.end()); 
        vector<int> r = {0};
        for(int i=0; i<N; ++i) 
            r.push_back(si[i].second);
        return r;
    }

    void permute(vector<int> permutation) {
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                a[i][j] = permutation[a[i][j]];
            }
        }
    }
 
    void swap_row(int i, int j) {
        for (int k=0; k<N; ++k) {
            swap(a[i][k], a[j][k]);
        }
    }

    void swap_col(int i, int j) {
        for (int k=0; k<N; k++) {
            swap(a[k][i], a[k][j]);
        }
    }

    void print() {
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                cout<<a[i][j];
            }
            cout << endl;
        }
    }
};

int main(int argc, char** argv) { 
    registerGen(argc, argv, 1);
    TGrid a, b;
    int best = b.score();
    auto t1 = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 rd(20);
    while (chrono::high_resolution_clock::now().time_since_epoch().count() - t1 < (long long)5e9) {
        int att = 255;
        while (att--) {
            int iter = 60;
            while (iter--) {
                int i1 = rnd.next(N);
                int i2 = rnd.next(i1 / G * G, (i1 / G + 1) *G - 1);
                int j1 = rnd.next(N);
                int j2 = rnd.next(j1 / G * G, (j1 / G + 1) *G - 1);
                a.swap_col(j1, j2);
                a.swap_row(i1, i2);
            }
            auto v = a.find_best_permute();
            a.permute(v);
            int score = a.score();
            if (score > best) {
                best = score;
                b = a;
            }
        }
    }
    b.print();
}