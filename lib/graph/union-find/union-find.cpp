// !hidden
#include "template.hpp"
// !endhidden

class UnionFind {
    const ll size;
    vll par;
    vll rank;

public:
    UnionFind(ll _size) : size(_size), par(size, -1), rank(size) {}

    ll root(ll v) {
        if (par[v] == -1) return v;
        return par[v] = root(par[v]);
    }

    bool same(ll x, ll y) {
        return root(x) == root(y);
    }

    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        return true;
    }
};
