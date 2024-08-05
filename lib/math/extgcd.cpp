// !hidden
#include "template.hpp"
// !endhidden

/// @brief 拡張ユークリッドの互除法
/// @param x ax + by = gcd(a, b) を満たす (x, y) が格納される
/// @param y ax + by = gcd(a, b) を満たす (x, y) が格納される
/// @return a と b の最大公約数
ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
