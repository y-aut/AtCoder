// !hidden
#include "template.hpp"
// !endhidden

// 約数列挙
vll factors(ll n) {
    vll ans{1};
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) ans.pb(i);
    }
    for (ll i = ans.size() - (ans.back() * ans.back() == n ? 2 : 1); i >= 0; i--) {
        ans.pb(n / ans[i]);
    }
    return ans;
}
