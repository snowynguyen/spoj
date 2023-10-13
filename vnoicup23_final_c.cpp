#include "bits/stdc++.h"
using namespace std;

unordered_set<int> vertices;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int query = 0;
    mt19937 rd(time(NULL));
    const int LIMIT = 15555;
    const int ATTEMPT_PER_VERTEX = 25;
    int r = 1;
    for (int i=2; i<=n; ++i) {
        vertices.insert(i);
    }
    
    for (;query < LIMIT;) {
        set<int> asked;
        bool found = false;
        for (int i=0; i<ATTEMPT_PER_VERTEX; ++i) {
            int u = rd() % n + 1;
            while (u == r) u = rd() % n + 1;
            cout << "adj " << u << endl;
            ++query;
            int x; cin >> x; 
            if (asked.count(x)) continue;
            asked.insert(x);
            cout << "subtree " << x << endl;
            ++query;
            int z; cin >> z;
            if (z * 2 >= n) {
                cout << "move " << x << endl;
                int _; cin >> _;
                ++query;
                r = x;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "found" << endl;
            return 0;
        }
    }
}