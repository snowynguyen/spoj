#include <bits/stdc++.h>
using namespace std;
const int N = 100002;
mt19937 rd (chrono::high_resolution_clock::now().time_since_epoch().count());

int rng (int lo, int hi) {
    return lo + rd() % (hi - lo + 1);
}

namespace CP{
    class SegTreeNode {
        public:
        int value;
        char color; 
        int wl, wr, bl, br;
        int longest;

        SegTreeNode(): value(0), color('X'), wl(0), wr(0), bl(0), br(0), longest(0) {

        }

        SegTreeNode operator+ (const SegTreeNode &h) const {
            SegTreeNode o;
            o.value = value + h.value;
            if (wl == value) {
                o.wl = wl + h.wl;
            } else {
                o.wl = wl;
            }
            if (bl == value) {
                o.bl = bl + h.bl;
            } else {
                o.bl = bl;
            }
            if (h.wr == h.value) {
                o.wr = h.wr + wr;
            } else {
                o.wr = h.wr;
            }
            if (h.br == h.value) {
                o.br = h.br + br;
            } else {
                o.br = h.br;
            }
            o.longest = max(max(longest, h.longest), max(wr + h.wl, br + h.bl));
            return o;
        }
    };

    class SegTree {
        public: 
        SegTreeNode f[N * 8]; 

        SegTree(int n) {
            for (int i=0; i<=4*n; ++i) 
                f[i] = SegTreeNode();
        }

        void update(int id, int l, int r, int p, char color, int value) {
            if (r < p || p < l) 
                return;
            if (l == r) {
                f[id].color = color;
                f[id].value = value;
                if (color == 'B') {
                    f[id].bl = f[id].br = value;
                    f[id].wl = f[id].wr = 0;
                    f[id].longest = value;
                } else {
                    f[id].bl = f[id].br = 0;
                    f[id].wl = f[id].wr = value;
                    f[id].longest = value;
                }
                return;
            }
            int m = (l + r) / 2;
            update(id * 2, l, m, p, color, value);
            update(id * 2 + 1, m + 1, r, p, color, value);
            f[id] = f[id * 2] + f[id * 2 + 1];
        }
    };

    class Solution {
        public: 
        int n, q;
        vector<int> a;

        void input() {
            cin>>n>>q;
            a.assign(q, 0);
            for (int &x:a) cin >> x;
        }

        vector<int> brute() {
            string v = string(n + 1, 'W');
            
            vector<int> ans;   
            for (int x : a) {
                v[x] = 'B' + 'W' - v[x];
                
                int l = 1;
                for (int c = 1,i=2; i<=n; ++i) {
                    if (v[i] == v[i-1]) c++;
                    else c = 1;
                    l = max(l, c);
                }
                ans.push_back(l);
            }
            return ans;
        }

        vector<int> solve() {
            vector<int> y = a; 
            y.push_back(0); y.push_back(n+1);
            sort(y.begin(), y.end());

            map<int, int> pos_to_segtreeid; 
            int segtreeid = 0;
            vector<int> treevalue = {0};
            string treecolor;
            pos_to_segtreeid[0] = segtreeid++;
            for (int i=1; i<=q+1; ++i) {
                if (y[i] == y[i-1] + 1) {
                    treevalue.push_back(1);
                    pos_to_segtreeid[y[i]] = segtreeid++;
                } else if (y[i] == y[i-1]) {

                }
                else {
                    treevalue.push_back(y[i] - y[i-1] - 1);
                    segtreeid++;
                    treevalue.push_back(1);
                    pos_to_segtreeid[y[i]] = segtreeid++;
                }
            }
            treevalue[segtreeid-1] = 0;
            treecolor = "X" + string(segtreeid - 2, 'W') + "X";
            SegTree st(segtreeid);

            for (int i=0; i<segtreeid; ++i) {
                st.update(1, 0, segtreeid - 1, i, (i == 0 || i == (segtreeid - 1)) ? 'X' : 'W', treevalue[i]);
            }

            vector<int> answer;

            for (int x : a) {
                int xid = pos_to_segtreeid[x];
                treecolor[xid] = 'B' + 'W' - treecolor[xid];
                st.update(1, 0, segtreeid - 1, xid, treecolor[xid], treevalue[xid]);
                int best = st.f[1].longest;
                answer.push_back(best);
            }
            return answer;
        }
    } ;

    void main() {
        Solution sol; 
        sol.input();
        auto ans = sol.solve();
        for (int x : ans) cout << x << '\n';
    }

    Solution generate(int n, int q) {
        Solution sol;
        sol.n = n; sol.q = q;
        sol.a = {};
        for (int i=0; i<q; ++i) {
            sol.a.push_back(rng(1, n));
        }
        return sol;
    }

    template<typename T> void print(vector<T> a, ostream &s = cout) {
        for (auto x : a) {
            s << x << ' ';
        }
        s << '\n';
    }

    void test() {
        while(true) {
            Solution sol = generate(9, 22); 
            auto a = sol.brute();
            auto b = sol.solve();
            if (a == b) continue;
            cout << "TEST =====================" << endl;
            cout << sol.n << ' ' << sol.q << endl;
            print(sol.a);
            cout << "ANS" << endl;
            print(a);
            cout << "OUT" << endl;
            print(b);
            if (a != b) return;
        }
    }
}

int main() 
{
    CP::test();
    return 0;
}