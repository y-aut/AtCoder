#include "lib/graph/tree/tree.cpp"

template <class T>
class ReRooting : Tree {
    // index[i][j]: edges[i][j] からみて，i が何番目の頂点か
    vvll index;

    vector<vector<T>> dp;
    vector<T> res;

    const function<T()> e;
    const function<T(T, T)> op;
    const function<T(T, ll)> mapping;

public:
    // 単方向の辺を受け取る
    ReRooting(const vvll &_edges, function<T()> _e, function<T(T, T)> _op, function<T(T, ll)> _mapping)
        : Tree(_edges, 0), index(size, vll()), res(size), e(_e), op(_op), mapping(_mapping) {

        // dict[i][j]: i からみて，j が何番目の頂点か
        vector<um<ll, ll>> dict(size, um<ll, ll>());
        rep(i, size) rep(j, edges[i].size()) dict[i][edges[i][j]] = j;
        rep(i, size) repi(j, edges[i]) index[i].pb(dict[j][i]);
        rep(i, size) dp.pb(vector<T>(edges[i].size(), e()));

        if (size == 1) {
            res[0] = mapping(e(), 0);
        } else {
            init();
        }
    }

    T get(ll node) { return res[node]; }

private:
    void init() {
        auto order = get_preorder();

        // from leaf
        for (ll i = order.size() - 1; i >= 1; i--) {
            auto node = order[i];
            auto parent = parents[node];

            T accum = e();
            ll parent_i = -1;
            rep(j, edges[node].size()) {
                if (edges[node][j] == parent) {
                    parent_i = j;
                    continue;
                }
                accum = op(accum, dp[node][j]);
            }
            dp[parent][index[node][parent_i]] = mapping(accum, node);
        }

        // to leaf
        rep(i, order.size()) {
            auto node = order[i];

            T accum = e();
            vector<T> accums_rev(edges[node].size());
            accums_rev[accums_rev.size() - 1] = e();

            for (ll j = accums_rev.size() - 1; j >= 1; j--)
                accums_rev[j - 1] = op(dp[node][j], accums_rev[j]);

            rep(j, accums_rev.size()) {
                dp[edges[node][j]][index[node][j]] =
                    mapping(op(accum, accums_rev[j]), node);
                accum = op(accum, dp[node][j]);
            }
            res[node] = mapping(accum, node);
        }
    }
};
