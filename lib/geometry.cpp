#include "../tpl/template.cpp"

#pragma region "多角形"

class Polygon {
    const ll size;
    // 時計回り or 反時計回り
    const vpll &points;

    // p1 -> p2 -> p3 が右曲がりか
    static bool is_cw(const pll &p1, const pll &p2, const pll &p3) {
        return (p2.first - p1.first) * (p3.second - p2.second) <=
               (p2.second - p1.second) * (p3.first - p2.first);
    }

public:
    Polygon(vpll &_points) : size(_points.size()), points(_points) {}

    ll get_size() const { return size; }
    pll get_point(ll i) const { return points[i]; }

    // 面積の2倍を求める
    ll get_area2() const {
        ll ans = 0;
        rep(i, size) {
            ans += (points[i].first - points[(i + 1) % size].first) *
                   (points[i].second + points[(i + 1) % size].second);
        }
        return abs(ans);
    }

    // 凸包を求める
    static Polygon get_convex_hull(const vpll &points) {
        sort(all(points), [](pll &a, pll &b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });

        auto q = deque<pll>();
        repi(p, points) {
            while (q.size() >= 2) {
                auto first = q.back();
                q.pop_back();
                auto second = q.back();
                if (!is_cw(second, first, p)) {
                    q.push_back(first);
                    break;
                }
            }
            q.push_back(p);
        }
        ll lower_size = q.size();
        rep(i, 1, points.size()) {
            while (q.size() - lower_size >= 1) {
                auto first = q.front();
                q.pop_front();
                auto second = q.front();
                if (is_cw(second, first, points[i])) {
                    q.push_front(first);
                    break;
                }
            }
            if (i != points.size() - 1)
                q.push_front(points[i]);
        }

        auto ans = vpll(all(q));
        return Polygon(ans);
    }
};

#pragma endregion

#pragma region "ConvexHullTrick"

// 追加する直線の傾きが単調である場合の ConvexHullTrick
template <typename T>
class ConvexHullTrick {
    // 直線群
    vector<pair<T, T>> lines;
    // 最小値(最大値)を求める x が単調であるか
    bool is_monotonic_x;
    // 最小/最大を判断する関数
    function<bool(T l, T r)> comp;
    // 単調クエリにおける探索位置
    int head = 0;

    // 直線 l1, l2, l3 のうち l2 が不必要であるかどうか
    bool check(pair<T, T> l1, const pair<T, T> &l2, pair<T, T> l3) const {
        if (l1 < l3) swap(l1, l3);
        return (l3.second - l2.second) * (l2.first - l1.first) >= (l2.second - l1.second) * (l3.first - l2.first);
    }

    // i 番目の直線 f_i(x) に対する x の時の値を返す
    T f(const int i, const T x) const {
        return lines[i].first * x + lines[i].second;
    }

public:
    ConvexHullTrick(
        const bool _is_monotonic_x = false,
        const function<bool(T l, T r)> _comp = [](T l, T r) { return l >= r; })
        : is_monotonic_x(_is_monotonic_x), comp(_comp) {
        lines.emplace_back(0, 0);
    };

    // 直線 y = ax + b を追加する
    void add(const T &a, const T &b) {
        pair<T, T> line(a, b);
        while (lines.size() >= 2 && check(*(lines.end() - 2), lines.back(), line))
            lines.pop_back();
        lines.emplace_back(line);
    }

    // 直線群の中で x の時に最小(最大)となる値を返す
    T get(const T &x) {
        // 最小値(最大値)クエリにおける x が単調
        if (is_monotonic_x) {
            while (lines.size() - head >= 2 && comp(f(head, x), f(head + 1, x)))
                ++head;
            return f(head, x);
        } else {
            int low = -1, high = lines.size() - 1;
            while (high - low > 1) {
                int mid = (high + low) / 2;
                (comp(f(mid, x), f(mid + 1, x)) ? low : high) = mid;
            }
            return f(high, x);
        }
    }
};

#pragma endregion

#pragma region "UnionRect"

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

#pragma endregion
