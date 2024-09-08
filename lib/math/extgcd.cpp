// !hidden
#include "template.hpp"
// !endhidden

/// @brief 拡張ユークリッドの互除法
/// @param x ax + by = gcd(a, b) を満たす (x, y) が格納される
/// @param y ax + by = gcd(a, b) を満たす (x, y) が格納される
/// @return a と b の最大公約数
TPL_T T extgcd(T a, T b, T &x, T &y) {
    if (b == T(0)) {
        x = T(1);
        y = T(0);
        return a;
    }
    T d = extgcd<T>(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
