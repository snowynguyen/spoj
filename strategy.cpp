#include "bits/stdc++.h"
using namespace std;

#define ld long double

struct Point {
    ld x, y;

    Point(ld x, ld y) : x(x), y(y) {}
};

std::ostream& dump(std::ostream &o, const Point& p)
{
    return o << round(p.x) << " " << round(p.y) << std::endl;
}

std::ostream& operator << (std::ostream &o,const Point &a){
return dump(o,a);
}

struct Solver {
    mt19937 rd;

    Solver(int seed = 121111111) : rd(seed) {}

    ld rdd(ld d) {
        ld epsilon = d / (1<<22);
        int ct = rd() & ((1<<22)-1);
        return ct * epsilon;
    }

    Point random_point() {
        return Point(rdd(120), rdd(90));
    }

    int main() {
        for (int i=0; i<11; ++i) {
            auto p = random_point();
            cout << p;
        }
        return 0;
    }

};

int main(int argc, char** argv) {
    Solver solver = Solver();
    solver.main();
    return 0;
}