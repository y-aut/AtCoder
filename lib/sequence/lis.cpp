// !hidden
#include "template.hpp"
// !endhidden

// 各 i に対して，A[0:i] の LIS を求める
vll get_lis(const vll &A) {
    vll ans, tmp;
    repi(a, A) {
        auto cnt = lower_bound(all(tmp), a) - tmp.begin();
        if (cnt == tmp.size()) {
            tmp.pb(a);
        } else {
            tmp[cnt] = a;
        }
        ans.pb(tmp.size());
    }
    return ans;
}
