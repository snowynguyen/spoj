#include <bits/stdc++.h>
using namespace std;

multiset<int> t;
multiset<int,  greater<int> > s;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while (q--) {
        char c;
        int a;
        cin >> c >> a;

        if (c == '+') {
            if (s.size() == t.size()) {
                s.insert(a);
            } else {
                t.insert(a);
            }
            
            if (t.size()) {
                auto p = *s.begin(), q = *t.begin();
                if (p>q) {
                    s.erase(s.begin());
                    t.erase(t.begin()); 
                    s.insert(q);
                    t.insert(p);
                }
            }

        } else { 
            if (s.find(a) != s.end()) {
                s.erase(s.find(a));
            }
            else {
                t.erase(t.find(a));
            }

            if (s.size() < t.size()) {
                s.insert(*t.begin());
                t.erase(t.begin());
            }

            if (s.size() == t.size() + 2) {
                t.insert(*s.begin());
                s.erase(s.begin());
            }
        }
        
        cout << *(s.begin()) << '\n';
    }
}