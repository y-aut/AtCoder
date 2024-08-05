// !hidden
#include "template.hpp"
// !endhidden

template <class Abel>
class WUnionFind {
    const ll size;
    vll par;
    vll rank;
    vector<Abel> diff_weight;

public:
    // SUM_UNITY はアーベル群の単位元
    WUnionFind(ll _size, Abel SUM_UNITY = 0) : size(_size), par(size, -1), rank(size),
                                               diff_weight(size, SUM_UNITY) {}

    ll root(ll v) {
        if (par[v] == -1) return v;
        auto r = root(par[v]);
        diff_weight[v] += diff_weight[par[v]];
        return par[v] = r;
    }

    Abel weight(ll v) {
        root(v);
        return diff_weight[v];
    }

    Abel diff(ll x, ll y) {
        return weight(y) - weight(x);
    }

    bool same(ll x, ll y) {
        return root(x) == root(y);
    }

    // weight(y) = weight(x) + w となるように merge する
    bool merge(ll x, ll y, Abel w) {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }
};
