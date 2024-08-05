// !hidden
#include "template.hpp"
// !endhidden

// 長方形の和集合の面積を求める O(nlogn)
class UnionRect {
    const vvll &rect;

    static pll op(const pll &a, const pll &b) {
        if (a.first == b.first) return {a.first, a.second + b.second};
        else if (a.first < b.first) return a;
        else return b;
    }
    static pll e() { return {LINF, 0}; }
    static pll mapping(ll f, const pll &x) { return {x.first + f, x.second}; }
    static ll composition(ll f, ll g) { return f + g; }
    static ll id() { return 0; }

    /// @brief 1 次元配列を座標圧縮する
    /// @param x 圧縮する配列
    /// @param xs 圧縮後の座標に対応する元の座標
    /// @return 圧縮後の配列
    vll get_compressed(const vll &x, vll &xs) {
        xs.clear();
        repi(i, x) xs.pb(i);
        sort(all(xs));
        xs.erase(unique(all(xs)), xs.end());

        vll ans(x.size());
        rep(i, x.size()) {
            ans[i] = lower_bound(all(xs), x[i]) - xs.begin();
        }
        return ans;
    }

public:
    /// @param _rect X1, X2, Y1, Y2 の順に格納された頂点の座標
    UnionRect(const vvll &_rect) : rect(_rect) {}

    ll get() {
        vll yraw, ys;
        repi(i, rect) {
            yraw.pb(i[2]);
            yraw.pb(i[3]);
        }
        auto ycmp = get_compressed(yraw, ys);

        vector<tuple<ll, ll, ll, ll>> ev;
        rep(i, rect.size()) {
            ev.pb({rect[i][0], 1, ycmp[i * 2], ycmp[i * 2 + 1]});
            ev.pb({rect[i][1], -1, ycmp[i * 2], ycmp[i * 2 + 1]});
        }
        sort(all(ev));

        // 区間の最小値および最小値の個数を持ち，区間加算を行う
        lazy_segtree<pll, op, e, ll, mapping, composition, id> tree(ys.size() - 1);
        rep(i, ys.size() - 1) tree.set(i, {0, ys[i + 1] - ys[i]});
        ll ans = 0, last_x = 0;
        for (auto [x, add, l, r] : ev) {
            auto res = tree.all_prod();
            ans += (x - last_x) * (ys.back() - ys.front() - (res.first == 0 ? res.second : 0));
            tree.apply(l, r, add);
            last_x = x;
        }
        return ans;
    }
};
