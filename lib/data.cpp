#include "../tpl/template.cpp"

#pragma region "区間を set で管理する"

/// @brief 開区間を set で管理する．
/// @tparam merge [3, 4), [4, 5) を [3, 5) と扱うかどうか．
template <bool merge>
class IntervalSet {
    set<pll> s;

    inline bool lt(ll x, ll y) const {
        if (merge) return x <= y;
        else return x < y;
    }

public:
    IntervalSet() {
        s.insert({-LINF, -LINF});
        s.insert({LINF, LINF});
    }

    set<pll> &get_set() { return s; }

    // 指定した区間と交わる区間を取得する
    vpll intersect(const pll &interval) {
        vpll ans;
        auto itr = prev(s.lower_bound(interval));
        if (itr->first <= interval.first && interval.first < itr->second) {
            ans.pb(*itr);
        }
        while (true) {
            itr++;
            if (interval.first <= itr->first && itr->first < interval.second) {
                ans.pb(*itr);
            } else break;
        }
        return ans;
    }

    // 区間を挿入し，マージする
    pll insert(const pll &interval) {
        ll x = interval.first, y = interval.second;
        auto itr = prev(s.lower_bound(interval));

        // 直前の区間が被っていたらマージする
        if (itr->first <= x && lt(x, itr->second)) {
            chmin(x, itr->first);
            chmax(y, itr->second);
            s.erase(itr);
        }
        itr = s.lower_bound({x, y});

        while (true) {
            if (x <= itr->first && lt(itr->first, y)) {
                chmax(y, itr->second);
                itr = s.erase(itr);
            } else break;
        }
        s.insert({x, y});
        return {x, y};
    }
};

#pragma endregion

#pragma region "MergeSortTree"

struct Node {
    vll sorted;

    Node() {}
    Node(const vll &_sorted) : sorted(_sorted) {
    }
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

#pragma endregion

#pragma region "区間集合の重なり"

// disjoint な区間集合 a, b の重なりの長さを求める
ll intersect(const vpll &a, const vpll &b) {
    ll ans = 0, apos = 0, bpos = 0;
    while (apos < a.size() && bpos < b.size()) {
        ans += max(0LL, min(a[apos].second, b[bpos].second) - max(a[apos].first, b[bpos].first));
        if (a[apos].second <= b[bpos].second) apos++;
        else bpos++;
    }
    return ans;
}

#pragma endregion

#pragma region "Segment Tree Beats"

class SegTreeBeats {
    ll n, n0;
    vll max_v, smax_v, max_c;
    vll min_v, smin_v, min_c;
    vll sum;
    vll len, ladd, lval;

    void update_node_max(ll k, ll x) {
        sum[k] += (x - max_v[k]) * max_c[k];

        if (max_v[k] == min_v[k]) {
            max_v[k] = min_v[k] = x;
        } else if (max_v[k] == smin_v[k]) {
            max_v[k] = smin_v[k] = x;
        } else {
            max_v[k] = x;
        }

        if (lval[k] != LINF && x < lval[k]) {
            lval[k] = x;
        }
    }
    void update_node_min(ll k, ll x) {
        sum[k] += (x - min_v[k]) * min_c[k];

        if (max_v[k] == min_v[k]) {
            max_v[k] = min_v[k] = x;
        } else if (smax_v[k] == min_v[k]) {
            min_v[k] = smax_v[k] = x;
        } else {
            min_v[k] = x;
        }

        if (lval[k] != LINF && lval[k] < x) {
            lval[k] = x;
        }
    }

    void push(ll k) {
        if (n0 - 1 <= k) return;

        if (lval[k] != LINF) {
            updateall(2 * k + 1, lval[k]);
            updateall(2 * k + 2, lval[k]);
            lval[k] = LINF;
            return;
        }

        if (ladd[k] != 0) {
            addall(2 * k + 1, ladd[k]);
            addall(2 * k + 2, ladd[k]);
            ladd[k] = 0;
        }

        if (max_v[k] < max_v[2 * k + 1]) {
            update_node_max(2 * k + 1, max_v[k]);
        }
        if (min_v[2 * k + 1] < min_v[k]) {
            update_node_min(2 * k + 1, min_v[k]);
        }

        if (max_v[k] < max_v[2 * k + 2]) {
            update_node_max(2 * k + 2, max_v[k]);
        }
        if (min_v[2 * k + 2] < min_v[k]) {
            update_node_min(2 * k + 2, min_v[k]);
        }
    }

    void update(ll k) {
        sum[k] = sum[2 * k + 1] + sum[2 * k + 2];

        if (max_v[2 * k + 1] < max_v[2 * k + 2]) {
            max_v[k] = max_v[2 * k + 2];
            max_c[k] = max_c[2 * k + 2];
            smax_v[k] = max(max_v[2 * k + 1], smax_v[2 * k + 2]);
        } else if (max_v[2 * k + 1] > max_v[2 * k + 2]) {
            max_v[k] = max_v[2 * k + 1];
            max_c[k] = max_c[2 * k + 1];
            smax_v[k] = max(smax_v[2 * k + 1], max_v[2 * k + 2]);
        } else {
            max_v[k] = max_v[2 * k + 1];
            max_c[k] = max_c[2 * k + 1] + max_c[2 * k + 2];
            smax_v[k] = max(smax_v[2 * k + 1], smax_v[2 * k + 2]);
        }

        if (min_v[2 * k + 1] < min_v[2 * k + 2]) {
            min_v[k] = min_v[2 * k + 1];
            min_c[k] = min_c[2 * k + 1];
            smin_v[k] = min(smin_v[2 * k + 1], min_v[2 * k + 2]);
        } else if (min_v[2 * k + 1] > min_v[2 * k + 2]) {
            min_v[k] = min_v[2 * k + 2];
            min_c[k] = min_c[2 * k + 2];
            smin_v[k] = min(min_v[2 * k + 1], smin_v[2 * k + 2]);
        } else {
            min_v[k] = min_v[2 * k + 1];
            min_c[k] = min_c[2 * k + 1] + min_c[2 * k + 2];
            smin_v[k] = min(smin_v[2 * k + 1], smin_v[2 * k + 2]);
        }
    }

    void _update_min(ll x, ll a, ll b, ll k, ll l, ll r) {
        if (b <= l || r <= a || max_v[k] <= x) {
            return;
        }
        if (a <= l && r <= b && smax_v[k] < x) {
            update_node_max(k, x);
            return;
        }

        push(k);
        _update_min(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _update_min(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void _update_max(ll x, ll a, ll b, ll k, ll l, ll r) {
        if (b <= l || r <= a || x <= min_v[k]) {
            return;
        }
        if (a <= l && r <= b && x < smin_v[k]) {
            update_node_min(k, x);
            return;
        }

        push(k);
        _update_max(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _update_max(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void addall(ll k, ll x) {
        max_v[k] += x;
        if (smax_v[k] != -LINF) smax_v[k] += x;
        min_v[k] += x;
        if (smin_v[k] != LINF) smin_v[k] += x;

        sum[k] += len[k] * x;
        if (lval[k] != LINF) {
            lval[k] += x;
        } else {
            ladd[k] += x;
        }
    }

    void updateall(ll k, ll x) {
        max_v[k] = x;
        smax_v[k] = -LINF;
        min_v[k] = x;
        smin_v[k] = LINF;
        max_c[k] = min_c[k] = len[k];

        sum[k] = x * len[k];
        lval[k] = x;
        ladd[k] = 0;
    }

    void _add_val(ll x, ll a, ll b, ll k, ll l, ll r) {
        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            addall(k, x);
            return;
        }

        push(k);
        _add_val(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _add_val(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void _update_val(ll x, ll a, ll b, ll k, ll l, ll r) {
        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            updateall(k, x);
            return;
        }

        push(k);
        _update_val(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _update_val(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    ll _query_max(ll a, ll b, ll k, ll l, ll r) {
        if (b <= l || r <= a) {
            return -LINF;
        }
        if (a <= l && r <= b) {
            return max_v[k];
        }
        push(k);
        ll lv = _query_max(a, b, 2 * k + 1, l, (l + r) / 2);
        ll rv = _query_max(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(lv, rv);
    }

    ll _query_min(ll a, ll b, ll k, ll l, ll r) {
        if (b <= l || r <= a) {
            return LINF;
        }
        if (a <= l && r <= b) {
            return min_v[k];
        }
        push(k);
        ll lv = _query_min(a, b, 2 * k + 1, l, (l + r) / 2);
        ll rv = _query_min(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(lv, rv);
    }

    ll _query_sum(ll a, ll b, ll k, ll l, ll r) {
        if (b <= l || r <= a) {
            return 0;
        }
        if (a <= l && r <= b) {
            return sum[k];
        }
        push(k);
        ll lv = _query_sum(a, b, 2 * k + 1, l, (l + r) / 2);
        ll rv = _query_sum(a, b, 2 * k + 2, (l + r) / 2, r);
        return lv + rv;
    }

public:
    SegTreeBeats(ll _n) : SegTreeBeats(_n, nullptr) {}
    SegTreeBeats(const vll &a) : SegTreeBeats(a.size(), a.data()) {}

    SegTreeBeats(ll _n, const ll *a) : n(_n),
                                       max_v(_n * 4), smax_v(_n * 4), max_c(_n * 4),
                                       min_v(_n * 4), smin_v(_n * 4), min_c(_n * 4),
                                       sum(_n * 4), len(_n * 4), ladd(_n * 4), lval(_n * 4) {
        n0 = 1;
        while (n0 < n) n0 <<= 1;

        for (ll i = 0; i < 2 * n0; ++i) ladd[i] = 0, lval[i] = LINF;
        len[0] = n0;
        for (ll i = 0; i < n0 - 1; ++i) len[2 * i + 1] = len[2 * i + 2] = (len[i] >> 1);

        for (ll i = 0; i < n; ++i) {
            max_v[n0 - 1 + i] = min_v[n0 - 1 + i] = sum[n0 - 1 + i] = (a != nullptr ? a[i] : 0);
            smax_v[n0 - 1 + i] = -LINF;
            smin_v[n0 - 1 + i] = LINF;
            max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 1;
        }

        for (ll i = n; i < n0; ++i) {
            max_v[n0 - 1 + i] = smax_v[n0 - 1 + i] = -LINF;
            min_v[n0 - 1 + i] = smin_v[n0 - 1 + i] = LINF;
            max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 0;
        }
        for (ll i = n0 - 2; i >= 0; i--) {
            update(i);
        }
    }

    // range minimize query
    void update_min(ll a, ll b, ll x) {
        _update_min(x, a, b, 0, 0, n0);
    }

    // range maximize query
    void update_max(ll a, ll b, ll x) {
        _update_max(x, a, b, 0, 0, n0);
    }

    // range add query
    void add_val(ll a, ll b, ll x) {
        _add_val(x, a, b, 0, 0, n0);
    }

    // range update query
    void update_val(ll a, ll b, ll x) {
        _update_val(x, a, b, 0, 0, n0);
    }

    // range minimum query
    ll query_max(ll a, ll b) {
        return _query_max(a, b, 0, 0, n0);
    }

    // range maximum query
    ll query_min(ll a, ll b) {
        return _query_min(a, b, 0, 0, n0);
    }

    // range sum query
    ll query_sum(ll a, ll b) {
        return _query_sum(a, b, 0, 0, n0);
    }
};

#pragma endregion
