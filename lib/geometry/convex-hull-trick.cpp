// !hidden
#include "template.hpp"
// !endhidden

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
