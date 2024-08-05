// !hidden
#include "template.hpp"
// !endhidden

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
