// !hidden
#include "template.hpp"
// !endhidden

/// @brief 連立方程式の解を求める．
/// @param a n * m 行列
/// @param b m 次元ベクトル
/// @return 0 行目に解の一つ，1 行目以降に解空間の基底が行ベクトルとして入る．解なしの場合は empty を返す
template <typename T>
vv<T> solve_linear(vv<T> a, v<T> b) {
    assert(!a.empty());
    ll n = a.size(), m = a[0].size();
    assert(m == b.size());
    ll rk = 0;
    rep(j, m) {
        if (rk == n) break;
        rep(i, rk, n) if (a[i][j] != 0) {
            swap(a[rk], a[i]);
            swap(b[rk], b[i]);
            break;
        }
        if (a[rk][j] == 0) continue;
        T c = T(1) / a[rk][j];
        repi(x, a[rk]) x *= c;
        b[rk] *= c;
        rep(i, n) if (i != rk) {
            T c = a[i][j];
            if (c == T(0)) continue;
            b[i] -= b[rk] * c;
            rep(k, j, m) { a[i][k] -= a[rk][k] * c; }
        }
        ++rk;
    }
    rep(i, rk, n) if (b[i] != 0) return {};
    vv<T> res(1, v<T>(m));
    vll pivot(m, -1);
    ll p = 0;
    rep(i, rk) {
        while (a[i][p] == 0) ++p;
        res[0][p] = b[i];
        pivot[p] = i;
    }
    rep(j, m) if (pivot[j] == -1) {
        v<T> x(m);
        x[j] = -1;
        rep(k, j) if (pivot[k] != -1) x[k] = a[pivot[k]][j];
        res.eb(x);
    }
    return res;
}
