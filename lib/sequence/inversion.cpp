// !hidden
#include "template.hpp"
// !endhidden

// 座標圧縮された数列に対して，転倒数を求める
ll get_inversion(const vll &A) {
    fenwick_tree<ll> ft(A.size());
    ll ans = 0;
    repd(i, A.size()) {
        ans += ft.sum(0, A[i]);
        ft.add(A[i], 1);
    }
    return ans;
}
