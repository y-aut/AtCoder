// !hidden
#include "template.hpp"
// !endhidden

struct Node {
    vll sorted;
    Node() {}
    Node(const vll &_sorted) : sorted(_sorted) {}
};

/// @brief Merge-sort Tree
/// @tparam op 結果を結合する演算
/// @tparam e `op` の単位元
/// @tparam appl `const Node&` と任意の引数を受け取り，処理した結果を返す
template <auto op, auto e, auto appl>
class MergeSortTree {
    ll _n;
    v<Node> nodes;

    void init(ll i, vll &v) {
        if (v.size() > 1) {
            vll lv, rv;
            lv.reserve(v.size() / 2);
            rv.reserve(v.size() / 2);
            rep(i, v.size() / 2) lv.pb(v[i]);
            rep(i, v.size() / 2, v.size()) rv.pb(v[i]);
            init(i * 2, lv);
            init(i * 2 + 1, rv);
            ll lp = 0, rp = 0;
            while (lp < (ll)lv.size() && rp < (ll)rv.size()) {
                if (lv[lp] <= rv[rp]) {
                    v[lp + rp] = lv[lp], lp++;
                } else {
                    v[lp + rp] = rv[rp], rp++;
                }
            }
            while (lp < (ll)lv.size()) v[lp + rp] = lv[lp], lp++;
            while (rp < (ll)rv.size()) v[lp + rp] = rv[rp], rp++;
        }
        nodes[i] = Node(v);
    }

public:
    MergeSortTree(const vll &v) {
        _n = 1;
        while (_n < (ll)v.size()) _n <<= 1;
        nodes.resize(_n * 2);
        auto ary = v;
        ary.resize(_n, LINF);
        init(1, ary);
    }

    template <typename... Params>
    auto query(ll l, ll r, Params... x) {
        l += _n;
        r += _n;
        auto sl = e(), sr = e();
        while (l < r) {
            if (l & 1) sl = op(sl, appl(nodes[l++], x...));
            if (r & 1) sr = op(appl(nodes[--r], x...), sr);
            l >>= 1;
            r >>= 1;
        }
        return op(sl, sr);
    }
};
