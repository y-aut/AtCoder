// !hidden
#include "template.hpp"
// !endhidden

// disjoint な区間集合 a, b の重なりの長さを求める
ll intersect_size(const vpll &a, const vpll &b) {
    ll ans = 0, apos = 0, bpos = 0;
    while (apos < a.size() && bpos < b.size()) {
        ans += max(0LL, min(a[apos].second, b[bpos].second) - max(a[apos].first, b[bpos].first));
        if (a[apos].second <= b[bpos].second) apos++;
        else bpos++;
    }
    return ans;
}
